--- core/unix/src/TUnixSystem.cxx.orig	2023-01-02 00:42:50.624730000 +0100
+++ core/unix/src/TUnixSystem.cxx	2023-01-02 00:23:34.413900000 +0100
@@ -180,7 +180,7 @@
 #   endif
 #   define HAVE_DLADDR
 #endif
-#if defined(R__MACOSX)
+#if defined(R__MACOSX) || defined(R__FBSD)
 #      define HAVE_BACKTRACE_SYMBOLS_FD
 #      define HAVE_DLADDR
 #endif
