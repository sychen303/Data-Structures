#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* head = NULL;
struct node* tail = NULL;

struct node* create(){
    int n;
    struct node *nn,*ptr;
    printf("Enter sizee:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        if(i==0){
            head = (struct node*)malloc(sizeof(struct node));
            ptr = head;
        }
        else{
            nn = (struct node*)malloc(sizeof(struct node));
            ptr->next = nn;
            ptr = nn;
        }
        scanf("%d",&ptr->data);
    }
    ptr->next = NULL;
    tail = ptr;
    return head;
}

struct node * enqueue(int n){
    struct node* nn;
    nn = (struct node*)malloc(sizeof(struct node));
    nn->data=n;
    tail->next=nn;
    tail = nn;
    tail->next=NULL;
    return tail;
}

struct node * dequeue(struct node * head){
    struct node* p;
    p = head;
    head = head->next;
    printf("Deleted is %d",p->data);
    free(p);
    return head;
}

void disp(struct node* head){
    struct node* p;
    for(p=head;p!=NULL;p=p->next){
        printf("%d\t",p->data);
    }
}

void rear(struct node* tail){
    printf("%d",tail->data);
}

void front (struct node* head){
    printf("%d",head->data);
}

int main(){
    head = create();
    disp(head);
    tail = enqueue(100);
    printf("\n\n\n\n\n");
    disp(head);
    tail = enqueue(421);
    printf("\n\n\n\n\n\n");
    disp(head);
    head = dequeue(head);
    printf("\n\n\n\n\n\n");
    disp(head);
    printf("\n\n\n\n\n\n\n");
    rear(tail);
    printf("\n\n\n\n\n");
    front(head);
}