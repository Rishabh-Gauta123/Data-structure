#include<stdio.h>
#include<stdlib.h>
#define N 8
int stack[N];
int top=-1;

int main()
{
    int choice;
    printf("note:if do you want to exit from the loop then enter any invalide choice.\n");
    printf("enter choice:\n1.push\n2.pop\n3.peek\n4.display\n5.empty\n6.full\n");
    do{
    printf("enter the value of choice:");
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
        display();
        break;
        case 5:
        empty();
        break;
        case 6:
        full();
        break;
        default:
        printf("invalide choice:\n");
    }

    }while(choice>=1&&choice<=6);
    
}
void display()
{
    int i;
    if(top==-1)
    {
        printf("stack is empty.\n");
    }
    else{
    printf("data in stack is:\n");
    for(i=top;i>=0;i--)
    {
        printf("%d ",stack[i]);
    }
    printf("\n");
  }
    
}

void push()
{
    int x;
    printf("enter the value of data:");
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
}
void pop()
{
    if(top==-1)
    {
        printf("undderflow condition.\n");
    }
    else{
        int x=stack[top];
        printf("the removing element from the stack is %d",x);
        top--;
        printf("\n");
    }
}
void peek()
{
    if(top==-1)
    {
        printf("underflow condition.\n");
    }
    else{
        printf("the top element of the stack is %d",stack[top]);
        printf("\n");
    }
}
void full()
{
    if(top==N-1)
    {
        printf("entire stack is full.\n");
    }
    else{
        printf("stack is not full.\n");
    }
}
void empty()
{
    if(top==-1)
    {
        printf("stack is empty.\n");
    }
    else{
        printf("stack is not empty.\n");
    }
}
