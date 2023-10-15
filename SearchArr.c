#include<stdio.h>

int main(){
    int n,pos,search,flag=0;
    printf("Enter the size of Array: ");
    scanf("%d",&n);
    int arr[n]; //Intialising Array
    printf("Enter the elements of the array line by line: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]); //Entering array elements
    }
    printf("[");
    for(int i=0;i<n;i++){
        printf("\t%d,",arr[i]); //Priting array elements
    }
    printf("]");
    printf("\n");
    printf("Enter the element to be found: ");
    scanf("%d",&search);
    for(int i=0;i<n;i++){ //Traversing the array
        if(arr[i]==search){ //Conditional checking if the element is present or not.
            flag = 1;
            pos = i; //Position is equal to i in zero indexing system. If you want to start with 1, then positison will be i+1.
        }
    }
    if(flag==1){
        printf("The element %d found at position %d.",search,pos);
    }
    else{
        printf("The element is not present");
    }
}