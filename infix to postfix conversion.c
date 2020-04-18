#include<stdio.h>
char stack[50]; // Stack declaration globally
int top = -1; // Top deceleration globally
void push(char x) // Function to push content
{ top=top+1;
    stack[top] = x;
}
char pop() // Function to pop content
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}
int priority_order(char x)  // Function for checking the priority of the operation
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
}

void main()
{
    char expression[50];
    char *ptr, x;
    printf("Enter the expression:: ");
    scanf("%s",expression);
    ptr = expression;
    while(*ptr != '\0')
    {
        if(isalnum(*ptr))
            printf("%c",*ptr);
        else if(*ptr == '(')
            push(*ptr);
        else if(*ptr == ')')
        {
            while((x = pop()) != '(')
                printf("%c", x);
        }
        else
        {
            while(priority_order(stack[top]) >= priority_order(*ptr))
                printf("%c",pop());
            push(*ptr);
        }
        ptr++;
    }
    while(top != -1)
    {
        printf("%c",pop());
    }
}
