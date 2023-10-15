#include <stdio.h>
#include <stdlib.h>
#define ms 5
int front = -1;
int rear = -1;
int queue[ms];

void enqueue(int n)
{
    if (rear == (ms - 1))
    {
        printf("FULL");
    }
    else
    {
        if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear++;
        }
        queue[rear] = n;
    }
}

void dequeue()
{
    if ((front == -1 && rear == -1) || (front > rear))
        printf("Queue is empty");
    else
    {
        printf("%d\t", queue[front]);
    }
    front++;
}

void disp(int queue[])
{
    if ((front == -1 && rear == -1) || (front > rear))
        printf("Queue is empty");
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d\t", queue[i]);
        }
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    dequeue();
    printf("\n\n\n\n\n\n");
    //dequeue();
    //dequeue();
    //dequeue();
    //dequeue();
    //dequeue();
    enqueue(70);
    enqueue(80);
    disp(queue);
}
