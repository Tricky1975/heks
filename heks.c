#include <stdio.h>
#include <stdbool.h>
#include <math.h>

//                      0  1  2  3   4  5  6  7   8  9  A  B   C  D  E  F  
//                      1         2        3         4         5         6         7
//             123456789012345678901234678901234567890123456789012345678901234567890123456789
#define basis "........ .. .. .. ..  .. .. .. ..  .. .. .. ..  .. .. .. ..  ................"

int fails = 0;

int hpos(i){ return (i*3)+(int)floor(i/4)+10; }

void showfile(char* file){
	char ln[18];
	char ch[2]; 
	printf("Reading: %s\n",file);
	FILE * bt = fopen(file,"rb");
	if (bt==NULL) { printf("= Error opening file\n"); fails++; return; }
	
	fclose(bt);
}


int main( int argc, char *argv[] )  {
	printf("HEKS - Built %s; %s\n",__DATE__,__TIME__);
	printf("Coded by: Tricky\n(c) Jeroen P. Broks -- released under the terms of the General Public License 3\n\n");
	if (argc<2) { 
		printf("Usage: heks <filename> [<filename> [ <filename> .....]]]\n\n");
		return 0;
	}
	for (int i=1;i<argc;i++) showfile(argv[i]);
	if (fails==1) 
		printf("\t1 file failed to load\n");
	else if (fails>1)
		printf("\t%d files failed to load\n",fails);
	return 0;
}
