#include<stdio.h>
#include<stdlib.h>
#define N 8
int queue[N];
int front=-1;
int rear=-1;
int main()
{
    int choice;
    printf("note:if do you want to exit from the loop then enter any invalide choice.\n");
    printf("enter choice:\n1.enqueue\n2.dequeue\n3.peek\n4.display\n");
    do{
    printf("enter the value of choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        enqueue();
        break;
        case 2:
        dequeue();
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
void enqueue()
{
    int value;
    printf("enter data which you want enqueue in the queue:");
    scanf("%d",&value);
    if(rear==N-1)
    {
        printf("overflow condition.\n");
    }
    else if(rear==-1&&front==-1)
    {
        front=rear=0;
        queue[rear]=value;
    }
    else{
        rear++;
        queue[rear]=value;
    }

}
void dequeue()
{
    if(front==-1&&rear==-1){
        printf("queue is empty.\n");
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else{
        front=front+1;
    }
}
void peek()
{
    if(rear==-1&&front==-1)
    {
        printf("queue is empty.\n");
    }
    else{
        printf("the topmost element of the quque ios %d",queue[rear]);
    }
}
void display()
{
    int i;
    if(rear==-1&&front==-1)
    {
        printf("queue is empty.\n");
    }
    else
    {
        printf("the data in the queue is:");
        for(i=front;i<=rear;i++){
            printf("  %d ",queue[i]);
        }
        printf("\n");
    }
}
