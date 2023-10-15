#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;
struct node *create()
{
    struct node *newnode, *head;
    int n;
    printf("Enter size: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            head = (struct node *)malloc(sizeof(struct node));
            head->next = NULL;
        }
        else
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->next = head;
            head = newnode;
        }
        scanf("%d", &head->data);
    }
    return (head);
}
void display(struct node *head)
{
    if (head == NULL)
    {
        printf("Stack underflow!");
        return;
    }
    else
    {
        struct node *ptr;
        ptr = head;
        for (ptr = head; ptr != NULL; ptr = ptr->next)
        {
            printf("%d\t", ptr->data);
        }
    }
    printf("%d\n");
}
struct node *push(struct node *head)
{
    int n;
    printf("Enter value to be inserted: ");
    scanf("%d", &n);
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = n;
    newnode->next = head;
    head = newnode;
    display(head);
    return (head);
}

struct node *pop(struct node *head)
{
    if (head == NULL)
    {
        printf("Stack underflow!!");
    }
    else
    {
        struct node *ptr;
        ptr = head;
        head = head->next;
        free(ptr);
        display(head);
        return (head);
    }
}
void peek(struct node *head)
{
    if (head == NULL)
    {
        printf("Stack underflow!");
    }
    else
    {
        printf("%d", head->data);
    }
}
int main()
{
    struct node *head = NULL;
    int choice, a;
    printf("Enter the number of times you want to perform operations on the stack? ");
    scanf("%d", &a);
    printf("Operations are:\n1.Creation\n2.Display\n3.Peek\n4.Push\n5.Pop\n");
    for (int i = 0; i < a; i++)
    {
        printf("\nEnter operation you want to perform: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            head = create();
            break;
        case 2:
            display(head);
            break;
        case 3:
            peek(head);
            break;
        case 4:
            head = push(head);
            break;
        case 5:
            head = pop(head);
            break;
        default:
            printf("Enter a valid choice!");
            break;
        }
    }
}