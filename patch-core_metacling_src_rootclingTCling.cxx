--- core/metacling/src/rootclingTCling.cxx.orig	2022-11-12 10:56:28.563535000 +0100
+++ core/metacling/src/rootclingTCling.cxx	2022-11-12 10:56:49.049417000 +0100
@@ -20,6 +20,11 @@
 
 #undef R__DLLEXPORT
 
+#ifdef __FreeBSD__
+char *__progname;
+char **environ;
+#endif
+
 #include "TROOT.h"
 #include "TCling.h"
 
