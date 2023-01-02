--- core/metacling/src/TCling.cxx.orig	2023-01-02 00:42:50.610669000 +0100
+++ core/metacling/src/TCling.cxx	2023-01-02 00:23:34.411972000 +0100
@@ -1249,6 +1249,8 @@
          true
 #elif defined(R__MACOSX)
          true
+#elif defined(R__FBSD)
+         true
 #else // Windows
          false
 #endif
@@ -3351,6 +3353,8 @@
    dl_iterate_phdr(callback_for_dl_iterate_phdr, &newLibs);
    for (auto &&lib: newLibs)
       RegisterLoadedSharedLibrary(lib.c_str());
+#elif defined(R__FBSD)
+   // do nothing
 #else
    Error("TCling::UpdateListOfLoadedSharedLibraries",
          "Platform not supported!");
