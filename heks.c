#include <stdio.h>
//                      0  1  2  3   4  5  6  7   8  9  A  B   C  D  E  F  
//                      1         2        3         4         5         6         7
//             123456789012345678901234678901234567890123456789012345678901234567890123456789
#define basis "........ .. .. .. ..  .. .. .. ..  .. .. .. ..  .. .. .. ..  ................"


void showfile(char* file){
	printf("Reading: %s\n",file);
}


int main( int argc, char *argv[] )  {
	printf("HEKS - Built %s; %s\n",__DATE__,__TIME__);
	printf("Coded by: Tricky\n(c) Jeroen P. Broks -- released under the terms of the General Public License 3\n\n");
	if (argc<2) { 
		printf("Usage: heks <filename> [<filename> [ <filename> .....]]]\n\n");
		return 0;
	}
	for (int i=1;i<argc;i++) showfile(argv[i]);
	return 0;
}
