#include <stdio.h>

int base8conv(int);

int n, n_8;

int main()
{
	for(n = 32; n <= 126 ; n++)
    {
        n_8 = base8conv(n);
        printf("Number %d in base 8: %d; in ascii: %c \n", n, n_8, n);
    }
	return 0;
	
}