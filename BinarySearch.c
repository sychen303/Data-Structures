#include <stdio.h>
#include <stdlib.h>

int bs(int a[], int start, int end, int f)
{
    int mid;
    if (start < end)
    {
        mid = (start + end) / 2;
        if (f == a[mid])
        {
            printf("Found at position %d",mid+1);
        }
        else if (f > a[mid])
        {
            start = mid + 1;
            bs(a, start, end, f);
        }
        else if (f < a[mid])
        {
            end = mid - 1;
            bs(a, start, end, f);
        }
    }
    else{
        return -1;
    }
}
int main()
{
    int n;
    printf("Enter size: ");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int f;
    printf("Enter element: ");
    scanf("%d", &f);
    int o;
    o=bs(a, 0, n, f);
    if(o==-1){
        printf("Not found");
    }
}