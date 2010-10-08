#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define LINES 10


void print_file(char *file)
{
	FILE *f;
	int pg_nu = 1, new_pg = 1, lc, c;

	assert(file != NULL);
	if ((f = fopen(file, "r")) != NULL) {
		while ((c = fgetc(f)) != EOF) {
			if (new_pg) {	
				printf("[%s] Page Number : %d \n\n", file, pg_nu);
				new_pg = 0;
				lc = 1;
			}	
			putchar(c);
			if (c == '\n' && ++lc > LINES) {
				putchar('\n');
				printf("[%s] Page %d Ends\n", file, pg_nu);
				printf("---------------------------------------------------------------------\n");
				new_pg = 1;
				pg_nu++;
			}	
		}
		if (!new_pg) {
			putchar('\n');
			printf("[%s] Page %d Ends\n", file, pg_nu);
			printf("---------------------------------------------------------------------\n");
		}
		putchar('\n');
		fclose(f);
	} 
}

int main(int argc, char *argv[])
{
	int i;

	if ( argc <2 ){
		printf("\tWrong usage!!!!\n\tUsage : %s file1 file2...\n",argv[0]);
		exit(0);
	}
	for (i = 1; i < argc; i++) {
	print_file(argv[i]);
	}
	return EXIT_SUCCESS;
}

