--- core/thread/src/TPosixThread.cxx.orig	2022-11-12 10:57:19.988609000 +0100
+++ core/thread/src/TPosixThread.cxx	2022-11-12 10:57:27.602587000 +0100
@@ -37,7 +37,7 @@
    pthread_attr_init(attr);
    
    if (affinity >= 0) {
-   #ifdef R__MACOSX
+   #if defined(R__MACOSX) || defined(R__FBSD)
       Warning("Run", "Affinity setting not yet implemented on MacOS");
    #else
       cpu_set_t cpuset;
