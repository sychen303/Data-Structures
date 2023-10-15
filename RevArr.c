#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int b[n];
    for(int j=0;j<n;j++){
        b[n-1-j]=a[j];
        }
    for(int k=0;k<n;k++){
        printf("%d",b[k]);
    }
    
}