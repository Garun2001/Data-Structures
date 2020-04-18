#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;

}*first=NULL;

void create(int A[],int n)
{
    int i;
    struct node *p,*last;
    first=(struct node*)malloc(sizeof(struct node));
    first->prev=NULL;
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++)
    {
        p=(struct node*)malloc(sizeof(struct node));
        p->data=A[i];
        p->next=last->next;
        p->prev=last;
        last->next=p;
        last=p;

    }

}

void display(struct node *p)
{
    while(p)
    {
        printf("%d \n",p->data);
        p=p->next;
    }

}

int length(struct node *p)
{
    int len=0;
    while(p)
    {
        len++;
        p=p->next;
    }
    return len;

}

void insert(struct node *p)
{
    int i,index,n;
    struct node *t;
    printf("ENTER THE POSITION AT WHICH U WANT TO INSERT:");
    scanf("%d",&index);
    if(index<0||index>length(p))
    {
        return;
    }
    printf("ENTER THE NUMBER WHICH U WANT TO INSERT:");
    scanf("%d",&n);

    if(index==0)
    {
        t=(struct node*)malloc(sizeof(struct node));
        t->data=n;
        t->prev=NULL;
        t->next=first;
        first->prev=t;
        first=t;
    }

    else
    {
        for(i=0;i<index-1;i++)
        {
            p=p->next;
        }
        t=(struct node*)malloc(sizeof(struct node));
        t->data=n;

        t->prev=p;
        t->next=p->next;
        if(p->next)
        {
            p->next->prev=t;
        }
        p->next=t;

    }

}

void Delete(struct node *p)
{
    int i,index;
    struct node *q;
    int x=-1;
    printf("ENTER THE POSITION OF THE NUMBER WHICH U WANT TO DELETE:\n");
    scanf("%d",&index);
    if(index<0||index>length(p))
    {
        return;
    }

    if(index==1)
    {
        first=first->next;
        if(first)
        {
            first->prev=NULL;
        }
        x=p->data;
        free(p);

    }
    else
    {
        for(i=0;i<index-1;i++)
        {
            p=p->next;
        }
        p->prev->next=p->next;
        if(p->next)
        {
            p->next->prev=p->prev;
        }
         x=p->data;
         free(p);

    }
}
int main()
{
    struct node *temp;
    int A[]={3,4,5,6,7,8};
    create(A,6);
    printf("THE DOUBLY LINKED LIST IS GIVEN BELOW:\n");
    display(first);
    printf("THE LENGTH OF THE DOUBLY LINKED LIST IS:%d\n",length(first));
    insert(first);
    printf("NOW THE NEW DOUBLY LINKED LIST AFTER INSERTION IS:\n");
    display(first);
    Delete(first);
    printf("NOW THE NEW DOUBLY LINKED LIST AFTER DELETION IS:");
    display(first);
    return 0;
}
