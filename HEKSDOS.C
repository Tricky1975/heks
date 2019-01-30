/*
// Lic:
// 	Heks
// 	Simple Hex viewer
// 	
// 	
// 	
// 	(c) Jeroen P. Broks, 2019, All rights reserved
// 	
// 		This program is free software: you can redistribute it and/or modify
// 		it under the terms of the GNU General Public License as published by
// 		the Free Software Foundation, either version 3 of the License, or
// 		(at your option) any later version.
// 		
// 		This program is distributed in the hope that it will be useful,
// 		but WITHOUT ANY WARRANTY; without even the implied warranty of
// 		MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// 		GNU General Public License for more details.
// 		You should have received a copy of the GNU General Public License
// 		along with this program.  If not, see <http://www.gnu.org/licenses/>.
// 		
// 	Exceptions to the standard GNU license are available with Jeroen's written permission given prior 
// 	to the project the exceptions are needed for.
// Version: 19.01.24
// EndLic
*/

#include <stdio.h>
/* #include <stdbool.h> */
#include <string.h>
#include <math.h>

/*
//                      0  1  2  3   4  5  6  7   8  9  A  B   C  D  E  F
//                      1         2        3         4         5         6         7
//             123456789012345678901234678901234567890123456789012345678901234567890123456789
*/
#define basis "........ .. .. .. ..  .. .. .. ..  .. .. .. ..  .. .. .. ..  ................"
#undef debug

void chat(char * message){
#ifdef debug
	printf("DEBUG: %s\n",message);
#endif
}

int fails = 0;

int hpos(int i){ return (i*3)+(int)floor(i/4)+9; }

long int streamsize(FILE *stream){
	long int sz;
	long int old = ftell(stream);
	fseek(stream, 0L, SEEK_END);
	sz = ftell(stream);
	fseek(stream, old, SEEK_SET);
	return sz;
}

union convertchar{
	char nc;
	unsigned char uc;
};

unsigned char mygetc(FILE * bt){
	union convertchar c;
	c.nc = fgetc(bt);
	return c.uc;
}


void showfile(char* file){
	char ln[9];
	char ch[4];
	unsigned char c;
	char mp;
	char cp;
	int size;
	int pos;
	FILE * bt;
	char wline[80];
	int i;
	printf("Reading: %s\n",file);
	bt  = fopen(file,"rb");
	if (bt==NULL) { printf("= Error opening file\n"); fails++; return; }
	size = streamsize(bt);
	printf("Size:     %d bytes\n",size);
	for (pos=0;pos<size;pos++){
		if (pos % 16 == 0) {
			chat("New line!");
			if (pos>0) printf("%s\n",wline);
			chat(basis);
			strcpy(wline, basis);
			chat("Hexing position");
			sprintf(ln,"%08X",pos);
			chat("Copy!");
			for (i=0;i<8;i++) {
				#ifdef debug
				printf("DEBUG: Copy %d\n",i);
				chat(wline);
				#endif
				wline[i]=ln[i];
			}
		}
		 c = mygetc(bt);
		/* //printf("?"); */
		sprintf(ch,"%02X",c);
		mp = pos%16;
		cp = hpos(mp);
		for (i=0;i<2;i++) wline[cp+i]=ch[i];
		if (c>31 && c<127) wline[mp+61]=c;
	}
	printf("%s\n",wline);
	fclose(bt);
}


int main( int argc, char *argv[] )  {
	int i;
	printf("HEKS - Built %s; %s\n",__DATE__,__TIME__);
	printf("Coded by: Tricky\n(c) Jeroen P. Broks -- released under the terms of the General Public License 3\n\n");
	if (argc<2) { 
		printf("Usage: heks <filename> [<filename> [ <filename> .....]]]\n\n");
		return 0;
	}
	for (i=1;i<argc;i++) showfile(argv[i]);
	if (fails==1) 
		printf("\t1 file failed to load\n");
	else if (fails>1)
		printf("\t%d files failed to load\n",fails);
	return 0;
}

