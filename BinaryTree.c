#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* lp;
    struct node* rp;
};

struct node* root = NULL;

struct node* create(int n){
    struct node* nn;
    nn = (struct node*)malloc(sizeof(struct node));
    nn->lp = NULL;
    nn->rp = NULL;
    nn->data = n;
    return nn;
}

struct node* insert(struct node* root, int n){
    if(root==NULL){
        return create(n);
    }
    else if(n<root->data){
        root->lp = insert(root->lp,n);
    }
    else if(n>root->data){
        root->rp = insert(root->rp,n);
    }
    return root;
}

void inorder(struct node* root){
    if(root==NULL){
        return;
    }
    else{
        inorder(root->lp);
        printf("%d ",root->data);
        inorder(root->rp);
    }
}

int main(){
    
    int n = 1;
    while(n>0){
        scanf("%d",&n);
        if(n>0)
            root=insert(root,n);
        else
            break;
    }
    inorder(root);
    return 0;
}