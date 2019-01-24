# Compile

This is very simple....


## On Mac

You need xcode to be installed and then you can just type on the terminal prompt: gcc -o heks heks.c


## On Linux

You do need a compiler which supports C99 for this and then you can just typ eon the prompt: gcc -o heks heks.c
Or if you really need to make sure the compiler goes for c99: c99 -o heks heks.c

## On Windows

You will likely need MinGW to do this. Now support for C99 is poor on Windows, but you can just try it: <your mingw path>\bin\gcc -o heks.exe heks.c
Of course, you may also try to get this to work on cygwin: gcc -o heks.exe heks.c






# NOTE!

When I wrote this document this source has only been tried on Mac, so I will need to sort out how other platforms will react.
