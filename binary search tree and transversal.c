#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
int *create()
{ int data;
struct node *root= (struct node*)malloc(sizeof(struct node));
printf("Enter the data in the root node.(-1 for no data.)\n");
scanf("%d",&data);
if(data==-1)
{
    printf("NO data is entered.\n");
    return NULL;
}
root->data=data;
printf("Enter the left data of the root data:%d\n",root->data);
root->left=create();
printf("Enter the right data of the root data:%d\n",root->data);
root->right=create();
}
void in_order(struct node* root)
{
    if(root == NULL)
    {return NULL;}
    in_order(root->left);
    printf("%d ->", root->data);
    in_order(root->right);

}
void pre_order(struct node* root)
{
    if(root == NULL)
    {return NULL;}
    printf("%d ->", root->data);
     pre_order(root->left);
    pre_order(root->right);
}
void post_order(struct node* root)
{
    if(root == NULL)
    {return NULL;}
    post_order(root->left);
    post_order(root->right);
    printf("%d ->", root->data);

}
void main()
{
struct node *root=create();
printf("In_order");
in_order(root);
printf("\nPre_order");
pre_order(root);
printf("\nPost order");
post_order(root);
}
