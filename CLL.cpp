#include <iostream>
#include <stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail= NULL;

struct node *create() // creates a circularly linged list
{
    int n;
    struct node *ptr, *nn; //*ptr for traversal and *nn for creation of newnode
    cout << "Enter the number of nodes: ";
    cin >> n; // Taking size from the user
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            head = (struct node *)malloc(sizeof(struct node)); // head node creation
            ptr = head;
        }
        else
        {
            nn = (struct node *)malloc(sizeof(struct node)); // creation of subsequent nodes
            ptr->next = nn;
            ptr = nn;
        }
        cout << "Enter data: ";
        cin >> ptr->data; // taking in data
    }
    ptr->next = head; // pointing the last node to head itself
    return head;
}

void disp(struct node *head) // displaying the cll, starting from head
{
    struct node *p;   // pointer for traversal
    if (head == NULL) // checking empty condition
    {
        cout << "List is empty";
    }
    else
    {
        cout << head->data << '\t';                  // printing the first element seperate
        for (p = head->next; p != head; p = p->next) // staring loop from 2nd node
        {
            cout << p->data << '\t'; // printing data
        }
    }
}

struct node *trackend(struct node *head)
{ // fucn to track the last(tail) pointer
    struct node *ptr;
    struct node *tail;
    for (ptr = head->next; ptr != head; ptr = ptr->next)
    {
        if (ptr->next == head)
        { // checks when does the next pointer point to head, indicating that it is the last node
            tail = ptr;
        }
    }
    return tail; // returning tail for future reference
}

/*struct node* deletebeg(struct node* head){
    struct node* end = trackend(head);
    struct node* p;
    p = head;
    head = p->next;
    end->next=p;
    free(p);
}*/

struct node *deletepos(struct node *head)
{                       // delete at a particular position
    struct node *p, *q; // pointer p for traversing and q for deleting that particular node
    int pos;
    cout << "Enter position";
    cin >> pos;
    int i = 0;
    for (p = head;; p = p->next)
    {
        if (p->next == head)   //if whole list is traversed, check this to tell whole list is traversed.
        {
            cout << "End of list has reached";
            break; //break is REALLY REALLY NECESSARY because as this a circular array, therefore it will traverse again and position will be (pos%n)
        }

        else if (i == pos - 2)
        {                      // taking pos-2 because position 2 means the second node. therefore if the person needs to delete the 2nd node, no traversal is needed as we have a pointer to that.
            q = p->next;       // pointing q to the address of to be deleted node
            p->next = q->next; // poining the current node to the node next to the to be deleted node, so the link is broken
            free(q);           // freeing the pointer pointing to the to be deleted node, therefore deleting the node
            break;
        }

        i++; // if we dont find the item, we move to the next node;
    }
    disp(head);
}
struct node* deleteend(struct node* head,struct node* tail){
    struct node* p;
    p = tail->next;
    tail->next=head;
    cout << tail->next;
    //free(p);
    return head;
}

int main()
{
    head = create();
    disp(head);
    //head = deletepos(head);
    //cout << endl << endl << endl;
    //disp(head);
    tail = trackend(head);
    head = deleteend(head,tail);
    disp(head);
}