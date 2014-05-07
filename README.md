libitl2: A library for Islamic calendar and prayer times
========================================================

`libitl2` is a fork from
[libitl](http://projects.arabeyes.org/project.php?proj=ITL). This fork aims
initially to:
* Move the code from the SVN SCM to git SCM
* Modernize the build system by moving it from `autotools` to `cmake`
* Do static analysis on the existing code and fix the found bugs
* Make the library cross-platform (i.e., runs natively on Unix/Linux, 
   Mac, and Windows)

Compiling
---------
In order to compile the library, you will need the following tools:
* A modern C compiler (e.g., GCC or Clang). Building the library has been tested
with GCC 4.8.1
* `cmake` (Tested with 2.8.11.2)

To compile the library and the demo programs, perform the followig 
commands in the `itl2` directory:

```shell
mkdir build
cd build
cmake ..
make
./demo_prayer # To run the prayer demo program
```

LICENSE
-------
The original `libitl` uses LGPL license shown in [LICENSE](LICENSE). `libitl2`
uses the same license as `libitl`.

AUTHORS
-------
The original authors of `libitl` can be found in [AUTHORS](AUTHORS). `libitl2`
is developed and maintained currently by Mohamed A. Bamakhrama.



