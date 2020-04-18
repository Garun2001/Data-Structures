#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;

}*first=NULL;

void create(int A[],int n)
{
    int i;
    struct node *p ,*last;
    first=(struct node*)malloc(sizeof(struct node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++)
    {
        p=(struct node*)malloc(sizeof(struct node));
        p->data=A[i];
        p->next=NULL;
        last->next=p;
        last=p;

    }

}

void display(struct node *p)
{
    while(p!=NULL)
    {
        printf("%d \n",p->data);
        p=p->next;

    }

}

int count(struct node *p)
{
    int temp=0;
    while(p)
    {
        temp++;
        p=p->next;

    }
    return (temp);

}


void insert(struct node *p)
{
    int index,n,i;
    struct node *t;
    printf("ENTER THE POSITION AT WHICH U WANT TO INSERT:");
    scanf("%d",&index);
    if(index<0||index>count(p))
    {
        return;
    }
    printf("ENTER THE NUMBER WHICH U WANT TO INSERT:");
    scanf("%d",&n);

    t=(struct node*)malloc(sizeof(struct node));
    t->data=n;
    if(index==0)
    {
        t->next=first;
        first=t;

    }
    else
    {
        for(i=0;i<index-1;i++)
        {
            p=p->next;
        }
        t->next=p->next;
        p->next=t;

    }

}

int deletion(struct node *p)
{
    int index,i;
    struct node *q;
    int x=-1;
    printf("ENTER THE POSITION THE NUMBER WHICH U WANT TO DELETE:");
    scanf("%d",&index);
    if(index<1||index>count(p))
    {
        return;
    }
    if(index==1)
    {
        q=first;
        x=first->data;
        first=first->next;
        free(q);
        return x;
    }
    else
    {
        for(i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }

        q->next=p->next;
        x=p->data;
        free(p);
        return x;
    }

}
int main()
{
    struct node *temp;
    int A[]={2,3,4,5,6};
    create(A,5);
    printf("THE LINKED LIST IS GIVEN BELOW:\n");
    display(first);
    insert(first);
    printf("NOW THE NEW LINKED LIST AFTER THE INSERTION IS:\n");
    display(first);
    deletion(first);
    printf("NOW THE NEW LINKED LIST AFTER THE DELETION IS:\n");
    display(first);
    return 0;
}
