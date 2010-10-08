#include<stdio.h>
#define ISUPPER(c) c >= 'A' && c <= 'Z'

int isupper(int c)

{
		return c >= 'A' && c <= 'Z';
}


main()
{
	printf("%d\n",ISUPPER('a'));

}
