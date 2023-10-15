#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
    struct node * lnext;
    int data;
    struct node * rnext;
};

struct node * head;

struct node* create_sll(){
    int n;
    struct node* ptr;
    struct node* newnode;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        if(i==1){
            head = (struct node*)malloc(sizeof(struct node*));
            head -> lnext = NULL;
            ptr = head;
        }
        else{
            newnode = (struct node*)malloc(sizeof(struct node*));
            ptr -> rnext = newnode;
            newnode -> lnext = ptr;
            ptr = newnode;
        }
       // ptr->rnext=NULL;
        printf("Enter data");
        scanf("%d",&ptr->data);
    }
    ptr->rnext=NULL;
    return(head);
}
void display_sll(struct node* head){
    struct node* ptr;
    for(ptr=head;ptr!=NULL;ptr=ptr->rnext){
        printf("%d",ptr->data);
    }
}

int main(){
    head = create_sll();
    display_sll(head);
}