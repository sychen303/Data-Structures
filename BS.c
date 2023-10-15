#include<stdio.h>

void bs(int a[],int l, int r, int flag){
    while(l<=r){
        int mid;
        mid = (l+r)/2;
        if(a[mid]==flag){
            printf("Found at %d",mid);
            return;
        }
        else if(a[mid]>flag){
            r = mid-1;
            bs(a,l,r,flag);
            return;
        }
        else{
            l = mid+1;
            bs(a,l,r,flag);
            return;
        }
    }
    printf("Not found");
    return;
}
int main(){
    int n;
    printf("Size?");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int k;
    printf("Element");
    scanf("%d",&k);
    bs(a,0,n,k);
}