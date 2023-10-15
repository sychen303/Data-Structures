#include<stdio.h>

int main(){
    int n,element,pos;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array line by line: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]); //Entering array elements
    }
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]); //Priting array elements
    }
    printf("\n");
    printf("Enter the element you want to delete: ");
    scanf("%d",&element);
    for(int i=0;i<n;i++){ //Traversing the array
        if(arr[i]==element){ //Conditional checking if the element is present or not.
            pos = i; //Position is equal to i in zero indexing system. If you want to start with 1, then positison will be i+1.
        }
    }
    printf("%d",pos);
    printf("\n");
    printf("\n");
    for(int i=pos;i<n;i++){
        arr[i]=arr[i+1]; 
    }
    if(pos<n){ //if deletion element is present it will present the array of n-1 size without that element.
        for(int i=0;i<n-1;i++){
        printf("%d\t",arr[i]); //Priting array elements
        }
    }
    else if(pos>=n) //if deletion element is not present in array it will print the whole array as it is.
    {
        printf("Element not present\n");
        for(int i=0;i<n;i++){
        printf("%d\t",arr[i]); //Priting array elements
        }
    }
}