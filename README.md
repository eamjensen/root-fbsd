# Fork of ROOT for patching for FreeBSD

This repository is a fork of [ROOT](https://github.com/root-project/root) which serves to document the few 
modifications to the ROOT source code which are needed in order to enable compilation and installation of ROOT 
in the FreeBSD ports tree.

On FreeBSD, the [ports tree](https://www.freebsd.org/ports/) is the entry point both for fetching pre-compiled packages
via the package manager `pkg` and for compilation and installation of software on any user's system.

Information on the ROOT port is available [here](https://www.freshports.org/devel/root/).

The port files located (e.g.) in the repository [here](https://cgit.freebsd.org/ports/tree/devel/root) are used
to build and install ROOT on FreeBSD.

## Pre-compiled package

ROOT can be installed on FreeBSD in `Release` mode (without debug symbols) via pkg: 

```shell
pkg ins root
```

This pre-compiled ROOT package comes with the features enabled by default in `OPTIONS_DEFAULT` in the 
[port Makefile](https://cgit.freebsd.org/ports/tree/devel/root/Makefile).

## Compilation of ROOT

ROOT can be compiled and installed on FreeBSD — by default in `Release` mode and with default features — 
via the ports tree:

```shell
cd /path/to/portstree/devel/root
make install
```

By default, if a FreeBSD port comes with any options, a menu will appear to let the user decide between them.
This behaviour can be disabled by adding the `BATCH` option:

```shell
make BATCH=1 install
```

The menu will no longer appear, and, if nothing else is specified, **all default options will be enabled**.

In order to install ROOT in `Debug` mode (with debug symbols), add the `WITH_DEBUG` option:

```shell
make WITH_DEBUG=1 install
```

In order to see all available features (as defined in `OPTIONS_DEFINE` in the 
[port Makefile](https://cgit.freebsd.org/ports/tree/devel/root/Makefile)), run

```shell
make showconfig
```

Features are enabled by providing a list of options to `WITH` and 
features are disabled by providing a list of options to `WITHOUT`:

```shell
make WITH="OPTION_1 OPTION_2 ..." WITHOUT="OPTION_M OPTION_M+1 ..." install
```

In order, for example, to build and install ROOT in `Debug` mode without graphics display capabilities, 
without Python bindings and with MySQL bindings, run

```shell
make BATCH=1 WITH_DEBUG=1 WITHOUT="X11 PYROOT" WITH="MYSQL" install
```

### Note on port building on different architectures

If the port fails to build on an architecture different from 'amd64', it is likely because `CMAKE_SYSTEM_PROCESSOR` 
(approximately equal to `CMAKE_HOST_SYSTEM_PROCESSOR`) is reported differently on FreeBSD as compared to on 
GNU/Linux/Cygwin/Android.

See [https://cmake.org/cmake/help/latest/variable/CMAKE_HOST_SYSTEM_PROCESSOR.html](https://cmake.org/cmake/help/latest/variable/CMAKE_HOST_SYSTEM_PROCESSOR.html).

Of the patches carried out on the ROOT source code, it is only the CMake code blocks in the file **SetUpLinux.cmake** 
which references system architecture.

Refer to the documentation in the given link and troubleshoot the identification of `CMAKE_SYSTEM_PROCESSOR` if you 
suspect a failed build is due to an as-of-yet unsupported FreeBSD architecture.
