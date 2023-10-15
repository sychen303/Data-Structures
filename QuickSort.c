#include<stdio.h>
void swap (int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int a[],int start,int end){
    int pindex = start;
    int pivot;
    pivot = a[end];
    int i;
    for(int i=start;i<end;i++){
        if(a[i]<pivot){
            swap(&(a[i]),&(a[pindex]));
            pindex++;
        }
    }
    swap(&(a[end]),&(a[pindex]));
    return pindex;
}

void qs(int a[],int start, int end){
    int pi;
    if(start<end){
        pi = partition(a,start,end);
        qs(a,start,pi-1);
        qs(a,pi+1,end);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    qs(a,0,n);
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}