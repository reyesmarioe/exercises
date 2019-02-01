#include<stdio.h>

int missing_number(int arr[], int n)
{
    /* Gauss function to calculate sum of consecutive number starting from 1 */
    int total = (n * (n +1)) / 2;
    int i;
    int sum = 0;

    for (i = 0; i < n - 1; i++) {
        sum += arr[i];
    }
    return total - sum;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 9};
        printf ("%d\n", missing_number(a, sizeof(a)/sizeof(a[0])));
}
