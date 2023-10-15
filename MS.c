#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int sno;
    int marks;
    char subject[20];
    struct node *next;
};

struct node *head;

struct node *readMarks()
{
    struct node *ptr, *nn;
    int n;
    printf("Enter the number of subjects: ");
    scanf("%d",&n);
    for (int i = 1; i < n+1; i++)
    {
        if (i == 1)
        {
            head = (struct node *)malloc(sizeof(struct node));
            ptr = head;
        }
        else
        {
            nn = (struct node *)malloc(sizeof(struct node));
            ptr->next = nn;
            ptr = nn;
        }
        printf("Enter marks for %d subject: ",i);
        ptr->sno = i;
        scanf("%d", &ptr->marks);
        gets(ptr->subject);
    }
    ptr->next=NULL;
    return head;
}

void display(struct node* head){
    struct node* ptr;
    printf("\n\n");
    printf("Marks with serial numbers are: \n\n");
    for(ptr=head;ptr!=NULL;ptr=ptr->next){
        printf("%d. %d",ptr->sno,ptr->marks);
        puts(ptr->subject);
        printf("\n");
    }
}

int max (struct node* head){
    int max;
    max = head->marks;
    struct node* ptr;
    for(ptr=head;ptr!=NULL;ptr=ptr->next){
        if((ptr->marks)>=max){
            max = ptr->marks;
        }
    }
    return max;
}

void maxsub (struct node* head, int max){
    struct node* ptr;
    for(ptr=head;ptr!=NULL;ptr=ptr->next){
        if(ptr->marks==max){
            printf("Maximum marks are %d, and are in%s\n",ptr->marks,ptr->subject);
        }
    }
}

int main(){
    head = readMarks();
    display(head);
    int n;
    n = max(head);
    maxsub(head,n);
}
