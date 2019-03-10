#include<stdio.h>
#include<stdlib.h>

int print_missing_or_repeated(int *arr, int s)
{
	int *hash_table = NULL;
	int i, j;

	// Use heap memory to store the table, we can also allocate an array.
	hash_table = (int*)calloc(sizeof(int), arr[s - 1]);

	for (i = 0; i < s; i++) {
		// Populate table
		hash_table[arr[i]] += 1;
	}

	printf ("Printing missing or reapeated\n");
	for (i = 0; i <= arr[s - 1]; i++) {
		// Missing numbers have a value of zero in the table
		// Repeated number have a value bigger than zero.
		if ( 1 != hash_table[i]) {
			printf ("%d ", i);
		}
	}
	printf ("\n");
}

int main(void)
{
	int a[] = {0, 3,4, 5,5, 9, 10, 10, 10};

	print_missing_or_repeated(a, sizeof(a)/sizeof(a[0]));
	return 0;
}
		

