#include "integer_validator.h"

int validate_int(char* integer_char)
{
	for (int i = 0; i < strlen(integer_char); i++)
	{
		if (!isdigit(integer_char[i]))
		{
			return -1;
		}
	}
	return 0;
}
