--- core/dictgen/src/rootcling_impl.cxx.orig	2022-11-12 10:54:51.720688000 +0100
+++ core/dictgen/src/rootcling_impl.cxx	2022-11-12 10:55:07.269918000 +0100
@@ -191,7 +191,7 @@
 #ifdef __APPLE__
     exepath = _dyld_get_image_name(0);
 #endif
-#if defined(__linux) || defined(__linux__)
+#if defined(__linux) || defined(__linux__) || defined(R__FBSD)
     char linkname[PATH_MAX];  // /proc/<pid>/exe
     char buf[PATH_MAX];     // exe path name
     pid_t pid;
