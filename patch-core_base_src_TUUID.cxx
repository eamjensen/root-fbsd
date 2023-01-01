--- core/base/src/TUUID.cxx.orig	2022-11-12 10:53:44.771657000 +0100
+++ core/base/src/TUUID.cxx	2022-11-12 10:54:14.833721000 +0100
@@ -140,6 +140,9 @@
 #include <sys/sysinfo.h>
 #endif
 #include <ifaddrs.h>
+#ifdef R__FBSD
+#include <sys/socket.h>
+#endif
 #include <netinet/in.h>
 #endif
 #include <chrono>
