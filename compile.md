# Compile

This is very simple....


## On Mac

You need xcode to be installed and then you can just type on the terminal prompt: gcc -o heks heks.c


## On Linux

You do need a compiler which supports C99 for this and then you can just typ eon the prompt: gcc -o heks heks.c
Or if you really need to make sure the compiler goes for c99: c99 -o heks heks.c

## On Cygwin

The command: gcc -o heks heks.c will do this, just like on Mac or Linux. Of course, you do need to have gcc installed on Cygwin. Although the Cygwin version does work on normal Windows, the Windows binary as noted below will not work in Cygwin.

## On Windows

You will likely need MinGW to do this. Now support for C99 is poor on Windows, but you can just try it: <your mingw path>\bin\gcc -o heks.exe heks.c
Of course, you may also try to get this to work on cygwin: gcc -o heks.exe heks.c

## On DOS

Yeah, you can run Heks in DOS, however, since Heks uses code that is pretty common in C today, it was not in the old DOS days. I used Borland Turbo C myself to compile for DOS, while running in DOSBox. In stead of heks.c you then have to use HEKSDOS.C as I adapted the code there for older C compilers. 
I do not recommend to use HEKSDOS.C to compile for any modern platform.




# NOTE!

When I wrote this document this source has only been tried on Mac, so I will need to sort out how other platforms will react.
