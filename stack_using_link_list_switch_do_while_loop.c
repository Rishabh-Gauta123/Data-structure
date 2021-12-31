#include<stdio.h>
#include<stdlib.h>
int main()
{
    int choice;
    printf("note:if do you want to exit from the loop then enter any invalide choice.\n");
    printf("enter choice:\n1.push\n2.pop\n3.peek\n4.display\n");
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
        default:
        printf("invalide choice:\n");
    }

    }while(choice>=1&&choice<=4);
    
}
struct node
{
    int data;
    struct node *next;
};
struct node *newnode,*temp,*top=0;
void push()
{
  int value;
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("enter data which you want push in the stack:");
  scanf("%d",&value);
  newnode->data=value;
  newnode->next=top;
  top=newnode;
  
}
void display()
{
    temp=top;
    if(top==0)
    {
        printf("empty stack:\n");
    }
    else
    {
        //printf("the data in stack is:\n");
        while(temp!=0)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
    printf("\n");
}
void peek()
{
    if(top==0)
    {
        printf("empty stack:\n");
    }
    else
    {
        printf("top element of stack is:%d",top->data);
    }
}
void pop()
{
    temp=top;
    if(top==0)
    {
        printf("stack is empty:\n");
    }
    else
    {
        printf("poping element is:%d\n",top->data);
        top=temp->next;
        free(temp);
    }
}