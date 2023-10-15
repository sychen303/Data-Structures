#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
}; struct node* head;

struct node* create();
void disp(struct node*);
struct node* rev(struct node*);

int main(){
    struct node* head;
    head = create();
    disp(head);
}
struct node* create(){
    struct node* ptr;
    struct node* newnode;
    int n;
    printf("Enter: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        if(i==1){
            head = (struct node*)malloc(sizeof(struct node));
            ptr = head;
        }
        else{
            newnode = (struct node*)malloc(sizeof(struct node));
            ptr->next = newnode;
            ptr=newnode;
        }
        printf("Enter data: ");
        scanf("%d",&ptr->data);
    }
    ptr->next=NULL;
    return head;
}
void disp(struct node* h){
    struct node* ptr;
    for(ptr=h;ptr!=NULL;ptr=ptr->next){
        printf("%d\t",ptr->data);
    }
}
struct node* rev(struct node* h){
    struct node* curr;
    struct node* prev;
    struct node* ptr;
    ptr=curr=prev=head;
    for(ptr=head;ptr!=NULL;ptr=ptr->next){
        prev=ptr->next;
        curr=prev->next;
    }
}