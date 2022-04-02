#include <stdio.h>
#include <string.h>

int third_digit(int);

int result[100], l_result, number, n;

int main()
{
	l_result = 0;
    
    printf("n = ");
    scanf("%u", &l_result);
    
	for(int i = 0 ; i < l_result ; i++){
        printf("Enter number: ");
        scanf("%u", &number);
        
        result[i] = third_digit(number);
    }
    
    for(int i = 0 ; i < l_result ; i++){
        printf("%u ", result[i]);
    }
    
	return 0;
	
}
