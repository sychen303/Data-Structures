#include<stdio.h>
int main(){
    int n,element,pos;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array line by line: ");
    for(int i=0;i<n-1;i++){
        scanf("%d",&arr[i]); //Entering array elements
    }
    for(int i=0;i<n-1;i++){
        printf("%d\t",arr[i]); //Priting array elements
    }
    printf("\n");
    printf("Enter the position for insertion: ");
    scanf("%d",&pos);
    printf("Enter the element you want to enter: ");
    scanf("%d",&element);
    for(int i=n-1;i>pos;i--){ //Shifting the elements of array forward by one position to vacate the position for addition
        arr[i]=arr[i-1];
    }
    arr[pos]=element; //NOTE:NOT FOLLOWING ZERO INDEXING HERE!! Assinging the position as the insertion value
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]); //Priting array elements
    }
}