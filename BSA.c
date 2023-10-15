#include<stdio.h>
int main(){
    int n;
    printf("Size");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int mid;
    int flag;
    scanf("%d",&flag);
    int l = 0;
    int indi = 0;
    int r = n;
    while(l<=r){
        mid = (l+r)/2;
        if(a[mid]==flag){
            printf("fount at position %d",mid);
            int indi = 1;
            break;
        }
        else if(a[mid]>flag){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    if(indi==0){
        printf("Not found");
    }
}