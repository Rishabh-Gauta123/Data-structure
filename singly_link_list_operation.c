#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head,*newnode,*temp,*prevnode,*nextnode;
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
    int count=0,data;
     head=0;
    while(n>count)
    {
       newnode=(struct node*)malloc(sizeof(struct node));
       printf("enter the data of node %d:\n",count+1);
       scanf("%d",&newnode->data);
       if(head==0)
       {
            head=temp=newnode;
       }
       else
        {
            temp->next=newnode;
            temp=newnode;
        }
         count++;
         newnode->next=0;
    }
}
void print()
{ 
    int i=0;
    temp=head;
    printf("data in link list is:\n");
    while(temp!=0)
    {
        printf("%d  ",temp->data);
        temp=temp->next;
        i++;
    }
    printf("\n");
    printf("the number of nodes in link list is:=%d\n",i);
} 
void insert_fp()
{
    int size,data;
    printf("enter the size of link list:\n");
    scanf("%d",&size);
    creation(size);
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the data which you want insert:\n");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
    print();
    printf("\n");
}
void insert_ep()
{
    int size,data;
    printf("enter the size of link list:\n");
    scanf("%d",&size);
    creation(size);
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the data which you want insert:\n");
    scanf("%d",&newnode->data);
    newnode->next=0;
    temp=head;
    while(temp->next!=0)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    print();
    printf("\n");
}
void insert_ap()
{
    int i=2,size,data,pos;
    printf("enter the size of link list:\n");
    scanf("%d",&size);
    creation(size);
    printf("enter the position on which you want insert data:\n");
    scanf("%d",&pos);
    if(pos>size)
    {
        printf("invalide expression:\n");
    }
    else
    {
        temp=head;
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter the data:\n");
        scanf("%d",&newnode->data);
        newnode->next=temp->next;
        temp->next=newnode;
        print();
    }
    printf("\n");
}
void delete_fp()
{
    int size;
    printf("enter the size of link list:\n");
    scanf("%d",&size);
    creation(size);
    if(head==0)
    {
        printf("empty link list:\n");
    }
    else
    {
        temp=head;
        head=head->next;
        free(temp);
    }
    print();
    printf("\n");
}
void delete_ep()
{
    int size;
    printf("enter the size of link list:\n");
    scanf("%d",&size);
    creation(size);
    if(head==0)
    {
        printf("empty list");
    }
    else
    {
        temp=head;
        while(temp->next!=0)
        {
            prevnode=temp;
            temp=temp->next;    
        }
        if(head==temp)
        {
            head=0;
            free(temp);
        }
        else
        {
            prevnode->next=0;
            free(temp);
        }
    }
    print();
}
void delete_ap()
{
    int size,pos,i=1;
    printf("enter the size of link list:\n");
    scanf("%d",&size);
    creation(size);
    printf("enter the value of position:\n");
    scanf("%d",&pos);
    if(pos>size)
    {
        printf("invalide expression:\n");
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