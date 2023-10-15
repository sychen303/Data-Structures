#include<stdio.h>

int top = -1;
int *p;

int* create(){
    int *p;
    int n;
    printf("Size?");
    scanf("%d",&n);
    int arr[n];
    p = arr;
    return p;
}

void push(int *p,int n){
    top++;
    *(p+top)=n;
}

void pop(int *p){
    printf("Popped Item is %d",p[top]);
    top--;
}

void disp(int *p){
    for(int i=0;i<=top;i++){
        printf("%d\n",*(p+i));
        i++;
    }
}

int main(){
    int *p;
    p = create();
    push(p,10);
    push(p,20);
    push(p,30);
    push(p,40);
    push(p,50);
    disp(p);
    
}
