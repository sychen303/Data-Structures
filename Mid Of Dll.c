#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* lnext;
    int data;
    struct node* rnext;
}; struct node* head;
struct node* create_dll(int n);
void disp_dll(struct node* head);
void disp_mid(struct node* head, int n);
int main(){
    int n;
    printf("Enter number of nodes");
    scanf("%d",&n);
    struct node* head;
    head = create_dll(n);
    disp_dll(head);
    disp_mid(head, n);
    
}
struct node* create_dll(int n){
    struct node* newnode;
    struct node* ptr;
    for(int i=1;i<=n;i++){
        if(i==1){
            head = (struct node*)malloc(sizeof(struct node));
            ptr = head;
            ptr -> lnext = NULL;
        }
        else{
            newnode = (struct node*)malloc(sizeof(struct node));
            ptr->rnext = newnode;
            newnode->lnext = ptr;
            ptr = ptr->rnext;
        }
        scanf("%d",&ptr->data);
    }
    ptr->rnext = NULL;
    return head;
}
void disp_dll(struct node* head){
    struct node* ptr;
    for(ptr=head;ptr!=NULL;ptr=ptr->rnext){
        printf("%d",ptr->data);
    }
}
void disp_mid(struct node* head, int n){
    struct node* ptr;
    struct node* temp;
    int count = 0;
    if(n%2!=0){
        for(ptr=head;ptr!=NULL;ptr=ptr->rnext){
            count++;
            if(count==(n/2+1)){
                printf("\n%d",ptr->data);
            }
        }
    }
    if(n%2==0){
        for(ptr=head;ptr!=NULL;ptr=ptr->rnext){
            count++;
            if(count==n/2){
                printf("\n%d",ptr->data);
                temp = ptr->rnext;
                printf(" %d",temp->data);
            }
        }
    }

}
