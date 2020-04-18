#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int size;
    int front ;
    int rear;
    int *q;
};

void create(struct queue *qt)
{
    printf("ENTER THE SIZE OF THE QUEUE:");
    scanf("%d",&qt->size);
    qt->front=qt->rear=-1;
    qt->q=(int *)malloc(qt->size*sizeof(int));
}

void Display(struct queue qt)
{
    for(int i=qt.front+1;i<=qt.rear;i++)
    {
        printf("%d",qt.q[i]);
        printf("\n");

    }

}

void enqueue(struct queue *qt,int x)
{
    if(qt->rear==qt->size-1)
    {
        printf("QUEUE IS FULL:");
    }
    else
    {
        qt->rear++;
        qt->q[qt->rear]=x;
    }
}

int dequeue(struct queue *qt)
{
    int x=-1;
    if(qt->front==qt->rear)
    {
        printf("QUEUE IS EMPTY:");
    }
    else
    {
        qt->front++;
        x=qt->q[qt->front];
    }

    return x;
}

int main()
{
    struct queue qt;
    create(&qt);
    enqueue(&qt,33);
    enqueue(&qt,22);
    enqueue(&qt,11);
    enqueue(&qt,10);
    enqueue(&qt,9);
    dequeue(&qt);

    Display(qt);
    return 0;

}
