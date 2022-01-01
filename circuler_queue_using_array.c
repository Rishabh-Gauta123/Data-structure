#include<stdio.h>
#include<stdlib.h>
#define N 3
int queue[N];
int front=-1;
int rear=-1;

int main()
{
    int choice;
    printf("note:if do you want to exit from the loop then enter any invalide choice.\n");
    printf("choice:\n1.enqueue\n2.dequeue\n3.display\n");
    do{
    printf("enter your choice:");
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
        display();
        break;
        default:
        printf("invalide choice.\n");
    }

    }while(choice>=1&&choice<=3);
}

void enqueue()
{
    int value;
    printf("enter the data which you want enqueue in the queue:");
    scanf("%d",&value);
    if(front==-1&&rear==-1)
    {
        front=rear=0;
        queue[rear]=value;
    }
    else if((rear+1)%N==front){
        printf("overflow condition.\n");
    }
    else{
        rear=(rear+1)%N;
        queue[rear]=value;
    }
}
void dequeue()
{
    if(front==-1&&rear==-1){
        printf("underflow condition.\n");
    }
    else if(rear==front){
        rear=front=-1;
    }
    else{
        front=(front+1)%N;
    }
}
void display()
{
    int i=front;
    if(front==-1&&rear==-1){
        printf("your queue is empty.\n");
    }
    else{
        printf("data in the queue is: ");
        while(i!=rear){
            printf(" %d ",queue[i]);
            i=(i+1)%N;
        }
        printf("%d",queue[rear]);
        printf("\n");
    }

}
