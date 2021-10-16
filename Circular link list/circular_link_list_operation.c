#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node *next;
};
struct node *head,*temp,*newnode,*prevnode,*nextnode;
int main()
{
    int option,choice;
    printf("\n1.insertion");
    printf("\n2.deletion\n");
    printf("enter the value of option:\n");
    scanf("%d",&option);

    switch(option)
    {
        case 1:
        printf("\n1.insertion at first position");
        printf("\n2.insertion at any positsion");
        printf("\n3.insertion at end position\n");
        printf("enter the value of choice on which you want to perform operation:\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            insert_fp();
            break;
            case 2:
            insert_ap();
            break;
            case 3:
            insert_ep();
            break;
            default:
            printf("invalide choice");
        }
        break;
        case 2:
        printf("\n1.deletion at first position");
        printf("\n2.deletion at any positsion");
        printf("\n3.deletion at end position\n");
        printf("enter the value of choice on which you want to perform operation:\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            delete_fp();
            break;
            case 2:
            delete_ap();
            break;
            case 3:
            delete_ep();
            break;
            default:
            printf("invalide choice");
        }
        break;
        default:
        printf("invalide choice");

    }
}
void creation(int n)
{
    head=0;
    int count=0;
    while(count<n)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter the data of node %d:\n",count+1);
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        temp->next=head;
        count++;
    }
}
void print()
{
    int i=0;
    if(head==0)
    {
        printf("empty list");
    }
    else
    {
        printf("the data in link list is:\n");
        temp=head;
        while(temp->next!=head)
        {
            printf("%d ",temp->data);
            temp=temp->next;
            i++;
        }
        printf("%d",temp->data);
        printf("\n");
        printf("no of node in link list is:%d",i+1);
    }
}
void insert_fp()
{
    int size;
    printf("enter  the size of link list:\n");
    scanf("%d",&size);
    creation(size);
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data which you want insert:\n");
    scanf("%d",&newnode->data);
    temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    newnode->next=head;
    head=newnode;
    temp->next=newnode;
    print();
}
void insert_ap()
{
    int size,pos,i=1;
    printf("enter the size of link list:\n");
    scanf("%d",&size);
    creation(size);
    printf("enter position on which you want insert node:\n");
    scanf("%d",&pos);
    if(pos<1||pos>size+1)
    {
        printf("invalide expression:\n");
    }
    if(pos==1)
    {
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data which you want insert:\n");
    scanf("%d",&newnode->data);
    temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    newnode->next=head;
    head=newnode;
    temp->next=newnode;
    }
    else
    {
        temp=head;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter data which you want insert:\n");
        scanf("%d",&newnode->data);
        newnode->next=temp->next;
        temp->next=newnode;
    }
    print();
}
void insert_ep()
{
    int size;
    printf("enter the size of link list:\n");
    scanf("%d",&size);
    creation(size);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=0;
    printf("enter data which you want insert:\n");
    scanf("%d",&newnode->data);
    temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=head;
    print();
}
void delete_fp()
{
    int size;
    printf("enter the size of link list:\n");
    scanf("%d",&size);
    creation(size);
    if(head==0)
    {
        printf("empty list");
    }
    if(head==temp)
    {
        head=0;
        free(temp);
    }
    else
    {
        temp=prevnode=head;
        while(prevnode->next!=head)
        {
            prevnode=prevnode->next;
        }
        head=head->next;
        free(temp);
        prevnode->next=head;
    }
    print();
}
void delete_ap()
{
    int size,pos,i=1;
    printf("enter the size of link list:\n");
    scanf("%d",&size);
    creation(size);
    printf("enter position on which you want delete node:\n");
    scanf("%d",&pos);
    if(temp==head)
    {
        head=0;
        free(temp);
    }
    if(pos==1)
    {
        temp=prevnode=head;
        while(prevnode->next!=head)
        {
            prevnode=prevnode->next;
        }
        head=head->next;
        free(temp);
        prevnode->next=head;
    }
    else
    {
        temp=head;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        nextnode=temp->next;
        temp->next=nextnode->next;
        free(nextnode);
    }
    print();
}
void delete_ep()
{
    int size;
    printf("enter the size of link list:\n");
    scanf("%d",&size);
    creation(size);
    if(temp==head)
    {
        head=0;
        free(temp);
    }
    else
    {
        temp=head;
        while(temp->next!=head)
        {
            prevnode=temp;
            temp=temp->next;
        }
        prevnode->next=head;
        free(temp);
    }
    print();
}