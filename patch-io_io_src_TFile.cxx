--- io/io/src/TFile.cxx.orig	2023-02-14 00:57:29.169696000 +0100
+++ io/io/src/TFile.cxx	2023-02-14 00:56:43.960947000 +0100
@@ -77,7 +77,9 @@
 #include <sys/stat.h>
 #ifndef WIN32
 #include <unistd.h>
+#ifndef R__FBSD
 #include <sys/xattr.h>
+#endif
 #else
 #   define ssize_t int
 #   include <io.h>
@@ -4067,7 +4069,7 @@
    TString expandedUrl(url);
    gSystem->ExpandPathName(expandedUrl);
 
-#ifdef R__UNIX
+#if defined(R__UNIX) && !defined(R__FBSD)
    // If URL is a file on an EOS FUSE mount, attempt redirection to XRootD protocol.
    if (gEnv->GetValue("TFile.CrossProtocolRedirects", 1) == 1) {
       TUrl fileurl(expandedUrl, /* default is file */ kTRUE);
