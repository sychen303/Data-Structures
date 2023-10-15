#include <stdio.h>

void selectionsort(int a[], int n)
{
    int minindex;
    int temp;
    int min;
    for (int i = 0; i < n; i++)
    {
        minindex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minindex])
            {
                minindex = j;
            }
        }
        if (minindex != i)
        {
            temp = a[i];
            a[i] = a[minindex];
            a[minindex] = temp;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}

int main()
{
    int n;
    printf("Size");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    selectionsort(a, n);
}