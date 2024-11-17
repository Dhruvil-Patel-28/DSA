// Radix sort

#include <stdio.h>

int count_sort(int arr[], int n, int exp)
{

    int countarr[10] = {0};

    for (int i = 0; i < n; i++)
        countarr[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        countarr[i] = countarr[i - 1] + countarr[i];

    int output[n];
    for (int i = n - 1; i >= 0; i--)
    {
        output[countarr[(arr[i] / exp) % 10] - 1] = arr[i];
        countarr[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

int radix_sort(int arr[], int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    
    for (int exp = 1; max / exp > 0; exp *= 10)
        count_sort(arr, n, exp);
}

int main()
{
    int n;
    printf("Enter the Number of Elements\n");
    scanf("%d", &n);

    int input[n];
    printf("Enter Elements\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &input[i]);

    printf("The sorted array is \n");
    radix_sort(input, n);

    for (int i = 0; i < n; i++)
        printf("%d\t", input[i]);
}