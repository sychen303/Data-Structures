#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* rnext;
    struct node* lnext;;
};
struct node* head;
int main() {
    struct node *newnode;
    struct node* ptr;
    int n;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        if(i==1){
            head = (struct node*)malloc(sizeof(struct node));
            ptr = head;
            head -> lnext = NULL;
        }
        else{
            newnode = (struct node*)malloc(sizeof(struct node));
            ptr->rnext=newnode;
            newnode->lnext = ptr;
            ptr = ptr->rnext;
            
        }
    scanf("%d",&ptr->data);
    }
    ptr -> rnext = NULL;
    struct node* p;
    for(p = head;p!=NULL;p=p->rnext){
        printf("%d",p->data);
    }
   

    return 0;
}
