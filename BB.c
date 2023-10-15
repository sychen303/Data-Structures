#include <stdio.h>

void bs(int a[], int n)
{ 
    int temp;
    for(int i=0;i<n;i++){
        for(int j = 1;j<n;j++){
            if(a[j-1]>a[j]){
                temp = a[j-1];
                a[j-1]=a[j];
                a[j]=temp;
            }
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
    bs(a,n);
}