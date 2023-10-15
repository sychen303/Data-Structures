#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node lc; // store address of left child
    struct node rc; // store address of right child
};
struct node *root; // main initial head node of the BST;

struct node *create()
{
    if (root == NULL)
    {
        printf("Tree does not exist.");
        return -1;
    }
    else
    {
        struct node *nn;
        nn = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &nn->data);
    }
}