--- core/metacling/src/TCling.cxx.orig	2023-02-13 16:21:06.798359000 +0100
+++ core/metacling/src/TCling.cxx	2023-02-13 16:21:06.794727000 +0100
@@ -1249,6 +1249,8 @@
          true
 #elif defined(R__MACOSX)
          true
+#elif defined(R__FBSD)
+         true
 #else // Windows
          false
 #endif
@@ -3366,6 +3368,8 @@
    dl_iterate_phdr(callback_for_dl_iterate_phdr, &newLibs);
    for (auto &&lib: newLibs)
       RegisterLoadedSharedLibrary(lib.c_str());
+#elif defined(R__FBSD)
+   // do nothing
 #else
    Error("TCling::UpdateListOfLoadedSharedLibraries",
          "Platform not supported!");
