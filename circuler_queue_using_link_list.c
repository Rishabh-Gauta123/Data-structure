#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

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

struct node *front=0;
struct node *rear=0;
struct node *temp;
void enqueue()
{
    int value;
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data which you want enqueu in the queue:");
    scanf("%d",&value);
    newnode->data=value;
    newnode->next=0;
    if(rear==0){
        front=rear=newnode;
        rear->next=front;
    }
    else{
        rear->next=newnode;
        rear=newnode;
        rear->next=front;
    }
}
void dequeue()
{
    temp=front;
    if(rear==0&&front==0)
    {
        printf("empty queue.\n");
    }
    else if(rear==front){
        front=rear=0;
        free(temp);
    }
    else{
        front=front->next;
        rear->next=front;
        free(temp);
    }
}
void display()
{
    temp=front;
    if(rear==0&&front==0)
    {
        printf("empty queue.\n");
    }
    else{
        printf("the data in the queue is:");
        while(temp->next!=front){
            printf(" %d ",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
        printf("\n");
    }

}
