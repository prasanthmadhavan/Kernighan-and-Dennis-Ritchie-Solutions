#include <stdio.h>
#include <ctype.h>
main(int argc, char* argv[])
{
	int c;

	while ((c = getchar()) != EOF){
		if(argv[1])
			putchar(tolower(c));
		else
			putchar(toupper(c));
	}
	return 0;
}
