#include<stdio.h>

int main(){
    int n;
    printf("Enter size of array: \n");
    scanf("%d",&n);
    int a[n];
    int choice;
    printf("Enter array elements: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter your choice.\n1.Sort in ascending order.\n2.Sort in descending order.\n");
    scanf("%d",&choice);
    int temp;
    if(choice==2){
        for(int i=0;i<n;i++){
            for(int j=0;j<n-1;j++){
                if(a[j]<a[j+1]){
                    temp=a[j+1];
                    a[j+1]=a[j];
                    a[j]=temp;
                }
            }
        }
    }
    if(choice==1){
        for(int i=0;i<n;i++){
            for(int j=0;j<n-1;j++){
                if(a[j]>a[j+1]){
                    temp=a[j+1];
                    a[j+1]=a[j];
                    a[j]=temp;
                }
            }
        }
    }
    printf("Sorted array is: ");
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}