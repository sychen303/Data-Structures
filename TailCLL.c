#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL; // globally delaring head, because head might change with every operation
struct node *tail = NULL; // similarly declaring tail as well
int size;                 // same for size as size will change after deletions

int s(struct node *head) // fucntion for size, it not useful on it's own but is getting called in every other fucntion
{
    if (head == NULL) // if list is empty, returns size as 0
    {
        return 0;
    }
    else // otherwise runs till it does not reach head in a circular fashion and returns the count of nodes.
    {
        struct node *ptr = head;
        int i = 0;
        do
        {
            ptr = ptr->next;
            i++;
        } while (ptr != head);
        return i;
    }
}

struct node *create() // function for creation
{
    int n;
    struct node *ptr, *nn;
    printf("Enter number of nodes: ");
    scanf("%d", &n); // taking number of nodes input from the user
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            head = (struct node *)malloc(sizeof(struct node)); // creating head
            ptr = head;
        }
        else
        {
            nn = (struct node *)malloc(sizeof(struct node)); // creating subsequent nodes
            ptr->next = nn;                                  // linking part
            ptr = nn;
        }
        printf("Enter data for node: ");
        scanf("%d", &ptr->data); // entering data into each node
    }
    ptr->next = head; // circularly linking it to the head
    size = s(head);   // calling the size fuction to get the number of nodes
    return head;
}

void disp(struct node *head) // fucntion for displaying
{
    if (head == NULL) // conditional checking for empty list
    {
        printf("List is empty.");
    }
    else
    {
        struct node *ptr = head;
        printf("Data is: ");
        // int i = 0;
        do // printing if list is not empty.
        {
            printf("%d\t", ptr->data); // using do while because with while, we have to explicitly print the head data. thats why a do while loop.
            ptr = ptr->next;
            // i++;
        } while (ptr != head /*i<10*/); // can keep i<2*size to check if last node is always connected to the first node or not
    }
}

void search(struct node *head) // function for searching
{
    if (head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        int ele;
        printf("Enter element for search.");
        scanf("%d", &ele);
        struct node *ptr;
        ptr = head;
        int i = 0;
        do // traversal of linked list and simply performing a linear search on ptr->data
        {
            i++;
            if (ptr->data == ele)
            {
                printf("Element found at position %d", i);
                return; // if found, exiting from function from the loop itself
            }
            ptr = ptr->next;
        } while (ptr != head);
        printf("Element not found."); // if not found, printing this and exiting from fucntion.
        return;
    }
}

struct node *trackend(struct node *head) // fucntion to track end to get tail, tail points to the last node of list
{
    if (head == NULL)
    {
        printf("List is empty.");
        return NULL;
    }
    struct node *tail, *ptr;
    ptr = head;
    do
    {
        ptr = ptr->next; // running till next pointer of a node is not head, if yes, then that node is the tail node itself.
    } while (ptr->next != head);
    tail = ptr; // storing the tail in globally declared tail
    return tail;
}

struct node *deletebeg(struct node *head, struct node *tail) // function to delete element in the beginning, taking both tail as head because both have to be changed.
{
    if (head == NULL)
    {
        printf("List is empty");
        return NULL;
    }
    else
    {
        struct node *p;
        p = tail->next;       // taking the node to be deleted in p, as tail points to the first node only
        tail->next = p->next; // storing the next of (to be deleted) node in next of tail, removing the link between tail and first  (to be deleted) node
        head = tail->next;    // doing the same delinking and linking process for head as mentioned above
        free(p);
        return head;
    }
}

struct node *deleteend(struct node *head, struct node *tail) // deleting end. that is deleting the tail node.
{
    if (head == NULL)
    {
        printf("List is empty");
        return NULL;
    }
    else
    {
        struct node *p, *q;
        p = head;
        do
        {
            p = p->next;
        } while (p->next != tail); // traversing the second last node, that is the node pointing to the tail
        p->next = tail->next;      // pointing the second last node(p) to the first node (tail->next);
        head = p->next;            // similarly poining head there.
        q = tail;                  // storing previous tail (the deleted last node) in a temp pointer
        tail = p;                  // assining tail the new value of p(second last node of the original list) as last node is deleted. So delinking process has been done.
        free(q);                   // freeing the node
        return head;
    }
}

struct node *deletepos(struct node *head, struct node *tail, int pos) // function to delete an element at a given position
{
    if (head == NULL)
    {
        printf("List is empty.");
        return NULL;
    }
    else
    {
        // int pos;
        struct node *p, *q;
        // printf("Enter the position for deletion:\n 1 being the first node and size for the last node");
        // scanf("%d", &pos);
        size = s(head);
        if (pos == 1) // if position is one, that means first node. So calling deletebeg function
        {
            head = deletebeg(head, tail);
            size = s(head); // as size will be reduced, calling size function
            return head;
        }
        else if (pos == size) // if position is size, that means the last node, therefore calling the deleteend function
        {
            head = deleteend(head, tail);
            size = s(head); // as size we be reduced, calling the size function
            return head;
        }
        else // if it is neither end not beginning
        {
            int i = 2;                             // taking i as 2 as it starts from second node
            for (p = head; p != tail; p = p->next) // taking p as head
            {
                if (i == pos)
                {
                    q = p->next;       // taking q as p->next because p->next is the second node
                    p->next = q->next; // taking p(head)->next as q->next. that is delinking the Ith and the (i+1)th node.
                    free(q);           // freeing the ith node
                    size = s(head);    // as size will be reduced
                    return head;
                }
                i++;
            }
        }
    }
}

struct node *deleteele(struct node *head, struct node *tail, int n) // for deleting element
{
    if (head == NULL)
    {
        printf("List is empty");
        return NULL;
    }
    else
    {
        struct node *ptr;
        // printf("Enter element to be deleted");
        int i = 1;
        ptr = head;
        do
        {
            if (ptr->data == n) // simply finding the position of element
            {
                head = deletepos(head, tail, i); // and then calling the deletepos function
                return head;                     // exiting the function
            }
            i++;
            ptr = ptr->next;
        } while (ptr != head);
        printf("Element not in the list"); // if element is not in the list, printing this as exiting the function
        return head;
    }
}

struct node *destroy(struct node *head) // function to destroy the list
{
    if (head == NULL)
    {
        printf("List is empty.");
        return NULL;
    }
    else
    {
        struct node *p, *q;
        p = head;
        do
        {
            q = p->next;
            free(p);
            p = q;
        } while (p != head);
        size = 0;
        return NULL;
    }
}

int main()
{
    int choice, num;
    printf("**Circularly Linked List**\nOperations available are\n1.Creation\n2.Searching\n3.Displaying\n4.Deletion\n5.Destruction of list\n6.Exit");
    int i = 1;
    while (i)
    {
        printf("\nEnter choice:");
        scanf("%d", &choice);
        int cc;
        switch (choice)
        {
        case 1:
            head = create();
            tail = trackend(head);
            break;
        case 2:
            search(head);
            break;
        case 3:
            disp(head);
            break;
        case 4:
            printf("Enter choice:\n1.By position\n2.By Element\n");
            scanf("%d", &cc);
            if (cc == 1)
            {
                int pos;
                printf("Enter position");
                scanf("%d", &pos);
                deletepos(head, tail, pos);
            }
            if (cc == 2)
            {
                int ele;
                printf("Enter Element");
                scanf("%d", &ele);
                deleteele(head, tail, ele);
            }
            break;
        case 5:
            head = destroy(head);
            break;
        case 6:
            i = 0;
            break;
        default:
            printf("Invalid choice");
            break;
        }
    }
}