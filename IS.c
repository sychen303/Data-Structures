#include <stdio.h>

void insertionSort(int a[], int n)
{
    int temp;
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            if (a[j - 1] > a[j])
            {
                temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    insertionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
}