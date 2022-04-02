#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

double square_root(int N, int precision)
{
	/*
		Returns an aproximate value for the sqare root of N with the given precision.
		praram N: (int) the given number
		param precision: (int) the precision
	*/
	int left = 0, right = N;
	int mid = 0;

	double sqr = 0;

	while (left <= right)
	{
		mid = (left + right) / 2;

		if (mid * mid == N)
		{
			sqr = mid;
			break;
		}

		if (mid * mid < N)
		{
			left = mid + 1;
			sqr = mid;
		}
		else
		{
			right = mid - 1;
		}
	}

	float increment = 0.1;
	int i = 0;
	for (i = 0; i < precision; i++)
	{
		while (sqr * sqr <= N)
		{
			sqr += increment;
		}

		sqr = sqr - increment;
		increment /= 10;
	}

	return sqr;
}

int prime(int n)
{
	/*
		Returns 1 if the given number is prime and 0 otherwise
		param n: (int) the given number
	*/
	int d = 0;

	if (n == 1 || n == 0)
	{
		return 0;
	}

	for (d = 2; d <= n / 2; d++)
	{
		if (n % d == 0)
		{
			return 0;
		}
	}

	return 1;
}

void print_menu()
{
	/*
		Prints the menu ui
	*/
	printf("Menu\n");
	printf("1. Square root of a number\n");
	printf("2. Longest subsequence such that the difference of any two consecutive elements is a prime number\n");
	printf("3. Read the vector of elements\n");
	printf("4. Exponent of prime number\n");
	printf("0. Exit\n\n");
	printf("option: ");
}

void square_root_ui()
{
	/*
		The ui for the square root calculation
	*/
	int N, precision;
	double sqr = 0;

	printf("Enter a number: ");
	scanf("%d", &N);

	printf("Enter the precision: ");
	scanf("%d", &precision);

	char str[41] = "The sqaure root of %d is: %.", decimals[13];

	sprintf(decimals, "%df", precision);

	strcat(str, decimals);

	sqr = square_root(N, precision);

	printf(str, N, sqr);
	printf("\n\n");
}

void read_vector(int** v, int* vector_size)
{
	/*
		Reads and allocates memory for a vector of elements
		param v: pointer to the pointer of the vector
		param vector_size: pointer to the vector's size
	*/
	int* v_c;

	if (*vector_size != 0)
	{
		free(*v);
	}

	printf("Read the length of the vector: ");

	scanf("%d", vector_size);

	v_c = (int*)malloc(*vector_size * sizeof(int));

	printf("Elements: ");

	int i = 0;
	for (i = 0; i < *vector_size; i++)
	{
		scanf("%d", &v_c[i]);
	}

	printf("\n");

	*v = v_c;
}

int* longest_subseq(int* v, int vector_size, int* subseq_length)
{
	/*
		Returns the longest subsequence such that the difference of any two consecutive elements is a prime number from the given vector
		param v: pointer to the vector of elements
		param vector_size: (int) the size of the vector
		param subseq_length: pointer to the length of the subsequence
	*/
	int poz = 0, length = 1, i = 0, max_length = 1;
	int* subseq;

	for (i = 1; i < vector_size; i++)
	{
		if (prime(abs(v[i] - v[i - 1])) == 0)
		{
			if (length > max_length)
			{
				max_length = length;
				poz = i - length;
			}
			length = 1;
		}
		else
		{
			length++;
		}
	}

	if (length > max_length)
	{
		max_length = length;
		poz = i - length;
	}

	subseq = (int*)malloc(max_length * sizeof(int));
	*subseq_length = max_length;
	
	for (i = poz; i < poz + max_length; i++)
	{
		subseq[i - poz] = v[i];
	}

	return subseq;
}

void longest_subseq_ui(int* v, int vector_size)
{
	/*
		The ui for the caalculation of the longest subsequence
		param v: pointer to the vector of elements
		param vector_size: (int) the size of the vector
		Returns if the vector is empty
	*/
	if (vector_size == 0)
	{
		printf("No elements added to the vector!\n\n");
		return;
	}

	int* subseq;
	int subseq_length, i = 0;

	subseq = longest_subseq(v, vector_size, &subseq_length);

	printf("Longest subsequence: ");

	for (i = 0; i < subseq_length; i++)
	{
		printf("%d ", subseq[i]);
	}

	printf("\n\n");

	free(subseq);
}

int exponent(int n, int p)
{
	/*
		Returns the exponent at which a given power appears in the decomposition of a given number
		param p: (int) the given power
		param n: (int) the given number
	*/
	int power = 0;

	while (n % p == 0)
	{
		power++;
		n /= p;
	}

	return power;
}

void exponent_ui()
{
	/*
		The ui for the calculation of the exponent
	*/
	int n, p, power;

	printf("Enter a number: ");
	scanf("%d", &n);

	printf("Enter the prime number: ");
	scanf("%d", &p);

	printf("\n");

	if (!prime(p)) {
		printf("%d is not a prime number\n\n", p);
		return;
	}

	power = exponent(n, p);

	if (power == 0)
	{
		printf("The number is not composed from %d\n\n", p);
	}
	else
	{
		printf("The exponent of %d from the decomposition of %d is: %d\n\n", p, n, power);
	}
}

void start()
{
	/*
		The main running function unifying all the othe functions, containing the main loop
	*/
	int is_running = 1, option, vector_size = 0;
	int* v = NULL;

	while (is_running)
	{
		print_menu();

		option = -1;

		scanf("%d", &option);

		printf("\n");

		switch (option)
		{
		case 1:
			square_root_ui();
			break;
		case 2:
			longest_subseq_ui(v, vector_size);
			break;
		case 3:
			read_vector(&v, &vector_size);
			break;
		case 4:
			exponent_ui();
			break;
		case 0:
			is_running = 0;
			break;
		default:
			printf("Invalid option\n\n");
			break;
		}
	}

	if (vector_size != 0)
	{
		free(v);
	}
}

int main()
{
	/*
		The main function which calls the start function to begin the program
	*/
	start();
	return 0;
}