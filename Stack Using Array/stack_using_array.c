#include<stdio.h>
#include<stdlib.h>
#define N 6
int stack[N];
int top=-1;

int main()
{
    int choice;
    printf("enter choice:\n1.push\n2.pop\n3.peek\n4.creation\n");
    printf("enter the value of choice:\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        push();
        break;
        case 2:
        pop();
        break;
        case 3:
        peek();
        break;
        case 4:
        creation();
        break;
        default:
        printf("invalide choice:\n");
    }
    
}
void creation()
{
    int i;
    
    printf("data in stack is:\n");
    for(i=top;i>=0;i--)
    {
        printf("%d ",stack[i]);
    }
    printf("\n");
    
}
void push()
{
    int x;
    printf("enter the value of x:\n");
    scanf("%d",&x);
    if(top==N-1)
    {
        printf("overflow condtion:\n");
    }
    else
    {
        top++;
        stack[top]=x;
    }
    creation();
}
void pop()
{
    int item;
    if(top==-1)
    {
        printf("underflow condition:\n");
    }
    else
    {
        item=stack[top];
        top--;
        printf("the value of poping data is %d:\n",item);
    }
    printf("\n");
}
void peek()
{
    int item;
    if(top==-1)
    {
        printf("underflow condition:\n");
    }
    else
    {
        item=stack[top];
        printf("the value of peek data is %d:\n",item);
    }
    printf("\n");
}