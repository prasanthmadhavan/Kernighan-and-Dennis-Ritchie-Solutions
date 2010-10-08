#include <stdio.h>
#include <stdarg.h>

void minscanf(char *fmt, ...);

int main()
{
	  int i;
	  char c;

	    minscanf("%c", &c);
	    printf("scanned %c\n", c);
	        
	        return 0;
}

void minscanf(char *fmt, ...)
{
	va_list ap;
	char *p;
	int *ival;
	char *cval;

	va_start(ap, fmt); 

	for (p = fmt; *p; p++) {

		if (*p != '%')
			continue;
		switch(*++p) {
				case 'd':
					ival = va_arg(ap, int *);
					scanf("%d", ival);
					break;
				case 'c':
					cval = va_arg(ap,char *);
					scanf("%c",cval);
					break;
				default:
					break;
		}
	}
}
