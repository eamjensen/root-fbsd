// @(#)root/gui:$Id$
// Author: Fons Rademakers   15/01/98

/*************************************************************************
 * Copyright (C) 1995-2000, Rene Brun and Fons Rademakers.               *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/


/** \class TRootGuiFactory
    \ingroup guiwidgets

This class is a factory for ROOT GUI components. It overrides
the member functions of the ABS TGuiFactory.

*/


#include "TRootGuiFactory.h"
#include "TRootApplication.h"
#include "TRootCanvas.h"
#include "TRootBrowser.h"
#include "TRootBrowserLite.h"
#include "TRootContextMenu.h"
#include "TRootControlBar.h"
#include "TROOT.h"
#include "TPluginManager.h"
#include "TEnv.h"

#include <iostream>

ClassImp(TRootGuiFactory);

////////////////////////////////////////////////////////////////////////////////
/// TRootGuiFactory ctor.

TRootGuiFactory::TRootGuiFactory(const char *name, const char *title)
   : TGuiFactory(name, title)
{
}

////////////////////////////////////////////////////////////////////////////////
/// Create a ROOT native GUI version of TApplicationImp

TApplicationImp *TRootGuiFactory::CreateApplicationImp(const char *classname,
                      Int_t *argc, char **argv)
{
   TRootApplication *app = new TRootApplication(classname, argc, argv);
   if (!app->Client()) {
      delete app;
      app = nullptr;
   }
   return app;
}

////////////////////////////////////////////////////////////////////////////////////////
/// Show warning that TWebCanvas will be started by default

void TRootGuiFactory::ShowWebCanvasWarning()
{
   static bool show_warn = true;
   if (!show_warn || gROOT->IsWebDisplay()) return;
   show_warn = false;

   std::cout << "\n"
                "ROOT comes with a web-based canvas, which is now being started. \n"
                "Revert to the legacy canvas by setting \"Canvas.Name: TRootCanvas\" in rootrc file or\n"
                "by starting \"root --web=off\".\n"
                "Find more info on https://root.cern/for_developers/root7/#twebcanvas\n";
}

////////////////////////////////////////////////////////////////////////////////
/// Create a ROOT native GUI version of TCanvasImp

TCanvasImp *TRootGuiFactory::CreateCanvasImp(TCanvas *c, const char *title,
                                             UInt_t width, UInt_t height)
{
   TString canvName = gEnv->GetValue("Canvas.Name", "TRootCanvas");
   if (canvName == "TWebCanvas") {
      auto ph = gROOT->GetPluginManager()->FindHandler("TCanvasImp", "TWebCanvas");

      if (ph && ph->LoadPlugin() != -1) {
         ShowWebCanvasWarning();
         auto imp = (TCanvasImp *) ph->ExecPlugin(6, c, title, 0, 0, width, height);
         if (imp) return imp;
      }
   }

   return new TRootCanvas(c, title, width, height);
}

////////////////////////////////////////////////////////////////////////////////
/// Create a ROOT native GUI version of TCanvasImp

TCanvasImp *TRootGuiFactory::CreateCanvasImp(TCanvas *c, const char *title,
                                  Int_t x, Int_t y, UInt_t width, UInt_t height)
{
   TString canvName = gEnv->GetValue("Canvas.Name", "TRootCanvas");
   if (canvName == "TWebCanvas") {
      auto ph = gROOT->GetPluginManager()->FindHandler("TCanvasImp", "TWebCanvas");

      if (ph && ph->LoadPlugin() != -1) {
         ShowWebCanvasWarning();
         auto imp = (TCanvasImp *) ph->ExecPlugin(6, c, title, x, y, width, height);
         if (imp) return imp;
      }
   }

   return new TRootCanvas(c, title, x, y, width, height);
}

////////////////////////////////////////////////////////////////////////////////
/// Create a ROOT native GUI version of TBrowserImp

TBrowserImp *TRootGuiFactory::CreateBrowserImp(TBrowser *b, const char *title,
                                               UInt_t width, UInt_t height,
                                               Option_t *opt)
{
   TString browserVersion(gEnv->GetValue("Browser.Name", "TRootBrowserLite"));
   TPluginHandler *ph = gROOT->GetPluginManager()->FindHandler("TBrowserImp",
                                                               browserVersion);
   TString browserOptions(gEnv->GetValue("Browser.Options", "FECI"));
   if (opt && strlen(opt))
      browserOptions = opt;
   browserOptions.ToUpper();
   if (browserOptions.Contains("LITE"))
      return new TRootBrowserLite(b, title, width, height);
   if (ph && ph->LoadPlugin() != -1) {
      TBrowserImp *imp = (TBrowserImp *)ph->ExecPlugin(5, b, title, width,
         height, browserOptions.Data());
      if (imp) return imp;
   }
   if (browserVersion.Contains("Lite", TString::kIgnoreCase))
      return new TRootBrowserLite(b, title, width, height);
   else
      return new TRootBrowser(b, title, width, height, browserOptions.Data());
}

////////////////////////////////////////////////////////////////////////////////
/// Create a ROOT native GUI version of TBrowserImp

TBrowserImp *TRootGuiFactory::CreateBrowserImp(TBrowser *b, const char *title,
                                               Int_t x, Int_t y, UInt_t width,
                                               UInt_t height, Option_t *opt)
{
   TString browserVersion(gEnv->GetValue("Browser.Name", "TRootBrowserLite"));
   TPluginHandler *ph = gROOT->GetPluginManager()->FindHandler("TBrowserImp",
                                                               browserVersion);
   TString browserOptions(gEnv->GetValue("Browser.Options", "FECI"));
   if (opt && strlen(opt))
      browserOptions = opt;
   browserOptions.ToUpper();
   if (browserOptions.Contains("LITE"))
      return new TRootBrowserLite(b, title, width, height);
   if (ph && ph->LoadPlugin() != -1) {
      TBrowserImp *imp = (TBrowserImp *)ph->ExecPlugin(7, b, title, x, y, width,
         height, browserOptions.Data());
      if (imp) return imp;
   }
   if (browserVersion.Contains("Lite", TString::kIgnoreCase))
      return new TRootBrowserLite(b, title, x, y, width, height);
   else
      return new TRootBrowser(b, title, x, y, width, height, browserOptions.Data());
}

////////////////////////////////////////////////////////////////////////////////
/// Create a ROOT native GUI version of TContextMenuImp

TContextMenuImp *TRootGuiFactory::CreateContextMenuImp(TContextMenu *c,
                                             const char *name, const char *)
{
   return new TRootContextMenu(c, name);
}

////////////////////////////////////////////////////////////////////////////////
/// Create a ROOT native GUI version of TControlBarImp

TControlBarImp *TRootGuiFactory::CreateControlBarImp(TControlBar *c, const char *title)
{
   if (gROOT->IsWebDisplay())
      return TGuiFactory::CreateControlBarImp(c, title);

   return new TRootControlBar(c, title);
}

////////////////////////////////////////////////////////////////////////////////
/// Create a ROOT native GUI version of TControlBarImp

TControlBarImp *TRootGuiFactory::CreateControlBarImp(TControlBar *c, const char *title,
                                                     Int_t x, Int_t y)
{
   if (gROOT->IsWebDisplay())
      return TGuiFactory::CreateControlBarImp(c, title, x, y);

   return new TRootControlBar(c, title, x, y);
}
