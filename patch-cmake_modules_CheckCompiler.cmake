--- cmake/modules/CheckCompiler.cmake.orig	2022-11-12 10:50:36.820891000 +0100
+++ cmake/modules/CheckCompiler.cmake	2022-11-11 17:27:16.094431000 +0100
@@ -202,7 +202,7 @@
 
 
 #---Setup details depending on the major platform type----------------------------------------------
-if(CMAKE_SYSTEM_NAME MATCHES Linux)
+if(CMAKE_SYSTEM_NAME MATCHES Linux OR CMAKE_SYSTEM_NAME MATCHES FreeBSD)
   include(SetUpLinux)
 elseif(APPLE)
   include(SetUpMacOS)
