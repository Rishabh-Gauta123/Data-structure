#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next,*prev;
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
    int count=0;
    head=0;
    while(count<n)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter the data of %d node:\n",count+1);
        scanf("%d",&newnode->data);
        newnode->next=0;
        newnode->prev=0;
        if(head==0)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
        count++;
    }
}
void print()
{
    int i=0;
    temp=head;
    printf("data in link list is:\n");
    while(temp!=0)
    {
        printf("%d ",temp->data);
        temp=temp->next;
        i++;
    }
    printf("\n");
    printf("number of nodes in link list are:%d",i);
}
void insert_fp()
{
    int size;
    printf("enter the size of link list:\n");
    scanf("%d",&size);
    creation(size);
    if(size==0)
    {
        printf("Sorry,there must be atleast one node:\n");
    }
    else
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->next=0;
        newnode->prev=0;
        printf("enter the value of data which you want insert:\n");
        scanf("%d",&newnode->data);
        head->prev=newnode;
        newnode->next=head;
        head=newnode;
        print();
    }   
}
void insert_ap()
{
    int size,pos,i=1;
    printf("enter the size of link list:\n");
    scanf("%d",&size);
    creation(size);
    if(size==0)
    {
        printf("Sorry,there must be atleast one node:\n");
    }
    else
    {
        printf("enter the position on which you want insert data:\n");
        scanf("%d",&pos);
        if(pos<1||pos>size+1)
        {
            printf("invalid expression:\n");
        }
        else if(pos==1)
        {
            newnode=(struct node*)malloc(sizeof(struct node));
            newnode->next=0;
            newnode->prev=0;
            printf("enter the value of data which you want insert:\n");
            scanf("%d",&newnode->data);
            head->prev=newnode;
            newnode->next=head;
            head=newnode;
        }
    
        else
        {
            temp=head;
            newnode=(struct node*)malloc(sizeof(struct node));
            newnode->next=0;
            newnode->prev=0;
            printf("enter the data which you want insert:\n");
            scanf("%d",&newnode->data);
            while(i<pos-1)
            {
                temp=temp->next;
                i++;
            }
            newnode->prev=temp;
            newnode->next=temp->next;
            temp->next=newnode;
            newnode->next->prev=newnode;
        } 
        print();  
    }
}
void insert_ep()
{
    int size;
    printf("enter the size of link list:\n");
    scanf("%d",&size);
    creation(size);
    if(size==0)
    {
        printf("Sorry,there must be atleast one node:\n");
    }
    temp=head;
    while(temp->next!=0)
    {
        temp=temp->next;
    }
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=0;
    newnode->prev=0;
    printf("enter data which you want insert:\n");
    scanf("%d",&newnode->data);
    temp->next=newnode;
    newnode->prev=temp;
    temp=newnode;
    print();
}
void delete_fp()
{
    int size;
    printf("enter the size of link list:\n");
    scanf("%d",&size);
    creation(size);
    if(size==0)
    {
        printf("invalid expression:\n");
    }
    if(size==1)
    {
        printf("no of node in link list are:0");
    }
    else
    {
        temp=head;
        head=head->next;
        head->next->prev=0;
        free(temp);
        print();
    }
}
void delete_ep()
{
    int size;
    printf("enter the size of link list:\n");
    scanf("%d",&size);
    creation(size);
    if(size==0)
    {
        printf("invalide expression");
    }
    else
    {
        temp=head;
        while(temp->next!=0)
        {
            prevnode=temp;
            temp=temp->next;
        }
        if(temp==head)
        {
            head=0;
            free(temp);
        }
        else
        {
            prevnode->next=0;
            free(temp);
        }
        print();
    }
}
void delete_ap()
{
    int size,pos,i=1;
    printf("enter the size of link list:\n");
    scanf("%d",&size);
    creation(size);
    if(size==0)
    {
        printf("invalide expression");
    }
    if(size==1)
    {
        printf("no of nodes in link list are:0");
    }
    else
    {
        temp=head;
        printf("enter the position:\n");
        scanf("%d",&pos);
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        print();
    }

}
