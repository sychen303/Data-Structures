#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
int top = -1;
int stack[MAXSIZE];
void push(int n);
void pop();
void display();
void peek();
int main(){
    int n;
    int choice;
    printf("1.Push\n2.Pop\n3.Display\n4.Peek\n5.Stop the program\n");
    printf("Enter the number of times you want to perform this operation: \n");
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d",&n);
            push(n);
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            peek();
            break;
        case 5:
            return 0;
        
        default:
            printf("Wrong input!!");
            break;
        }
    }
}
void push(int n){
    if(top==MAXSIZE){
        printf("Stack Overflow\n");
    }
    else{
        top++;
        stack[top]=n;
    }
}
void display(){
    int i=0;
    if(top==-1){
        printf("Stack underflow!!\n");
        return;
    }
    else{
        for(i=top;i>=0;i--){
            printf("%d\n",stack[i]);
        }
    }
    printf("\n");
}
void pop(){
    int n;
    if(top==-1){
        printf("Stack underflow\n");
    }
    else{
        n = stack[top];
        printf("Deleted element is %d\n",n);
        top--;
    }
}
void peek(){
    printf("Element at top is: %d\n",stack[top]);
}


 
