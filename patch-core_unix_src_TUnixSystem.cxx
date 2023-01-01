--- core/unix/src/TUnixSystem.cxx.orig	2022-11-12 10:57:57.209982000 +0100
+++ core/unix/src/TUnixSystem.cxx	2022-11-12 10:58:13.570543000 +0100
@@ -180,7 +180,7 @@
 #   endif
 #   define HAVE_DLADDR
 #endif
-#if defined(R__MACOSX)
+#if defined(R__MACOSX) || defined(R__FBSD)
 #      define HAVE_BACKTRACE_SYMBOLS_FD
 #      define HAVE_DLADDR
 #endif
