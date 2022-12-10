--- cmake/modules/SetUpLinux.cmake.orig	2022-11-12 10:49:59.188083000 +0100
+++ cmake/modules/SetUpLinux.cmake	2022-11-12 10:52:12.769662000 +0100
@@ -6,7 +6,7 @@
 
 set(ROOT_PLATFORM linux)
 
-if(CMAKE_SYSTEM_PROCESSOR MATCHES x86_64)
+if(CMAKE_SYSTEM_PROCESSOR MATCHES x86_64 OR CMAKE_SYSTEM_PROCESSOR MATCHES amd64)
   if(CMAKE_CXX_COMPILER_ID STREQUAL Intel)
     set(ROOT_ARCHITECTURE linuxx8664icc)
   else()
@@ -103,6 +103,10 @@
   endif()
 
   set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--no-undefined")
+
+  if(CMAKE_SYSTEM_NAME MATCHES FreeBSD)
+    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -lexecinfo -lcrypt")
+  endif()
 
   if(asan)
     # See also core/sanitizer/README.md for what's happening.
