# Fork of ROOT for patching for FreeBSD

Port available [here](https://www.freshports.org/devel/root/).

ROOT can be installed on FreeBSD via pkg: `pkg ins root`.

### Note on port building on different architectures

If the port fails to build on an architecture different from 'amd64', it is likely because `CMAKE_SYSTEM_PROCESSOR` (approximately equal to `CMAKE_HOST_SYSTEM_PROCESSOR`) is reported differently on FreeBSD as compared to on GNU/Linux/Cygwin/Android.

See [https://cmake.org/cmake/help/latest/variable/CMAKE_HOST_SYSTEM_PROCESSOR.html](https://cmake.org/cmake/help/latest/variable/CMAKE_HOST_SYSTEM_PROCESSOR.html).

Of the patches carried out on the ROOT source code, it is only the CMake code blocks in the file **SetUpLinux.cmake** which references system architecture.

Refer to the documentation in the given link and troubleshoot the identification of `CMAKE_SYSTEM_PROCESSOR` if you suspect a failed build is due to an as-of-yet unsupported FreeBSD architecture.

### Todo:

- [x] Resurrect port devel/root on freshports.org
- [x] Update to release 6.26/10
- [x] Compile against C++17, enabling compilation of experimental ROOT v7 features
