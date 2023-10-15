#include<iostream>
#include<cstdlib>
using namespace std;
struct node{
    int data;
    struct node* next;
};
struct node* head;

struct node* create(){
    int n;
    struct node* ptr, *nn;
    cout << "Enter size";
    cin >> n;
    for(int i=0;i<n;i++){
        if(i==0){
            head = (struct node*)malloc(sizeof(struct node));
            ptr=head;
            head->next=NULL;
        }
        else{
            nn = (struct node*)malloc(sizeof(struct node));
            ptr->next=nn;
            ptr=nn;
        }
        cout << "Enter data";
        cin >> ptr->data;
    }
    ptr->next=NULL;
    return head;
}
void disp(struct node* head){
    struct node* ptr;
    for(ptr=head;ptr!=NULL;ptr=ptr->next){
        cout << ptr->data << '\t';
    }
}
void search(struct node* head){
    int f;
    int pos;
    int c = 0;
    cout << "To be found?";
    cin >> f;
    struct node* ptr;
    int i=0;
    for(ptr=head;ptr!=NULL;ptr=ptr->next){
        i++;
        if(ptr->data==f){
            c = 1;
            pos = i;
            break;
        }
        else{
            c = 0;
        }
    }
    if(c==1){
        cout << "Element found at position " << pos;
    }
    else{
        cout << "Element not found";
    }
}
struct node* insert(struct node* head){
    int n;
    cout << "Element to be inserted?";
    cin >> n;
    int pos;
    cout << "At pos?";
    cin >> pos;
    struct node* ptr,*nn,*p;
    int i=0;
    for(ptr=head;ptr!=NULL;ptr=ptr->next){
        i++;
        if(i==pos){
            nn = (struct node*)malloc(sizeof(struct node));
            p = ptr->next;
            ptr->next = nn;
            nn->next = p;
            nn->data=n;
        }
    }
    disp(head);
}
struct node* dele(struct node* head){
    int pos;
    cout << "Deletion position?";
    cin >> pos;
    struct node* ptr, *q;
    int i=0;
    for(ptr=head;ptr!=NULL;ptr=ptr->next){
        i++;
        if((i+1)==pos){
            ptr->next=ptr->next->next;
        }
    }
    disp(head);
}
int main(){
    struct node* head;
    head = create();
    disp(head);
    search(head);
    insert(head);
    dele(head);
    disp(head);
}