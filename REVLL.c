#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* head;

struct node* create(){
    int n;
    struct node* ptr,*nn;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        if(i==0){
            head = (struct node*)malloc(sizeof(struct node));
            ptr=head;
        }
        else{
            nn = (struct node*)malloc(sizeof(struct node));
            ptr->next=nn;
            ptr=nn;
        }
        scanf("%d",&ptr->data);
    }
    ptr->next=NULL;
    return head;
}

void disp(struct node* head){
    struct node* ptr;
    ptr=head;
    for(ptr=head;ptr!=NULL;ptr=ptr->next){
        printf("%d",ptr->data);
    }
}

struct node* rev(struct node* head){
    struct node* prev, *curr, *next;
    prev = NULL;
    curr = head;
    next = NULL;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

int main(){
    head = create();
    disp(head);
    rev(head);
    disp(head);
}


