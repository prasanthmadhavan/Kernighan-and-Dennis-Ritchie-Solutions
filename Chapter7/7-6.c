#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 1000



int j=0;
int print( char *first, char *second, int linenu )

{
	if(strcmp (first, second) < 0 || strcmp (first, second) > 0){
		printf( "%d<%s\n%d>%s\n", linenu, first, linenu, second);
		j = 1;
	}
	return j;
}



int main(int argc, char *argv[] )
{
	FILE *fp1, *fp2;
	char fp1_line[LEN], fp2_line[LEN];
	int i;
	if ( argc != 3 ){
		printf("Wrong usage!!!!\nusage : %s file1 file2\n",argv[0]);
		exit(0);
	}
	fp1 = fopen( argv[1], "r" );
	if ( ! fp1 ){
		printf("Error!! Unable to open file %s\n", argv[1]);
	}
	fp2 = fopen( argv[2], "r" );
	if ( ! fp2 ){
		printf("Error!! Unable to open file %s\n", argv[2]);
	}
	i = 0;
	while ( (fgets(fp1_line, LEN, fp1) != NULL) && (fgets(fp2_line, LEN, fp2) != NULL)){
		print( fp1_line, fp2_line, i );
		i++;
	}
	if(j==0)
		printf("Files Match!!!\n");
	return 0;
}
