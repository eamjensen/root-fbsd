--- build/unix/compiledata.sh.orig	2022-11-12 10:49:06.326644000 +0100
+++ build/unix/compiledata.sh	2022-11-11 17:27:16.091990000 +0100
@@ -58,7 +58,7 @@
 
 # Remove the flags turning warnings into errors or extending
 # the number of warnings.
-CXXFLAGS=`echo $CXXFLAGS | sed -e 's/-Werror //g' -e 's/-Werror=\S* //g' -e 's/-Wall //g' -e 's/-Wshadow //g'  `
+CXXFLAGS=`echo $CXXFLAGS | sed -e 's/-Werror //g' -e 's/-Werror=[^[[:space:]]]* //g' -e 's/-Wall //g' -e 's/-Wshadow //g'  `
 
 # Determine the compiler version
 BXX="`basename $CXX`"
