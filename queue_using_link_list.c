#include<stdio.h>
#include<stdlib.h>

int main()
{
    int choice;
    printf("note:if do you want to exit from the loop then enter any invalide choice.\n");
    printf("choice:\n1.enqueue\n2.dequeue\n3.peek\n4.display\n");
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

struct node{
    int data;
    struct node *next;
};
struct node *front=0;
struct node *rear=0;
struct node *newnode;
void enqueue(){
    int value;
    printf("enter data which you want inqueue in the queue:");
    scanf("%d",&value);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=0;
    if(front==0&&rear==0){
        front=rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
}
void dequeue()
{
    struct node *temp;
    temp=front;
    if(front==0&&rear==0){
        printf("Empty queue.\n");
    }
    else{
        front=front->next;
        free(temp);
    }
}
void peek()
{
    if(front==0&&rear==0){
        printf("Empty queue.\n");
    }
    else{
        printf("the topmost element of thre queue is %d",rear->data);
        printf("\n");
    }

}
void display()
{
    struct node *temp;
    if(front==0&&rear==0){
        printf("Empty queue.\n");
    }
    else{
        temp=front;
        printf("the data in the queue is:");
        while(temp!=0)
        {
            printf(" %d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

