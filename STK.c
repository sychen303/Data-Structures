#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head;

struct node* create(){
    int n;
    struct node *nn;
    printf("Size");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        if(i==0){
            head = (struct node*)malloc(sizeof(struct node));
            head->next=NULL;
        }
        else{
            nn = (struct node*)malloc(sizeof(struct node));
            nn->next = head;
            head = nn;
        }
        scanf("%d",&head->data);
    }
    return head;
}

void disp(struct node* head){
    struct node* ptr;
    for(ptr=head;ptr!=NULL;ptr=ptr->next){
        printf("%d\n",ptr->data);
    }
}

struct node* push(struct node* head,int n){
    struct node* nn;
    nn = (struct node*)malloc(sizeof(struct node));
    nn->next = head;
    nn->data = n;
    head = nn;
    return head;
}

struct node* pop(struct node* head){
    struct node* p;
    p = head;
    head = head->next;
    free(p);
    return head;
}

void pee(struct node* head){
    printf("%d",head->data);
}

int main(){
    head = create();
    disp(head);
    head = push(head,100);
    head = push(head,200);
    disp(head);
    head = pop(head);
    disp(head);
    printf("\n\n\n\n\n");
    pee(head);
}