#include<iostream>
#include<string>
#include<cmath>
using namespace std;

struct node{
    int data;
    node *next;
};

class Queue{
public:
node *front=0,*newnode,*temp,*rear=0;
void enqueue(){
int value,i;
i=0;
cout<<"Note:for inserting data in the Queue press 1 at the place of value otherwise press 0. "<<endl;
cout<<"enter value: ";
cin>>value;
while(value!=0){
      if(value==1){
          
    cout<<"enter data:";
    newnode=new node;
    cin>>newnode->data;
    newnode->next=0;

    if(front==0 && rear==0){
        front=rear=newnode;
        rear->next=front;
    }else{
        rear->next=newnode;
        rear=newnode;
        rear->next=front;
      }
      i++;
      newnode->next=0;
      cout<<"enter value: ";
      cin>>value;
    }
    else{
        cout<<"you did not press correct key."<<endl;
        break;
    }
      }

  }
  void prints(){
    temp=front;
    int k=0;
    if(front==0 && rear==0){
        cout<<"Sorry,No Data in tha LinkList";
    }else{
        cout<<"data of the linklist is:";
        while(temp->next!=front){
        cout<<temp->data<<" ";
        temp=temp->next;
        k++;
    }
    }
    cout<<endl;
    cout<<"the size of the link list is:"<<k;
    cout<<endl;
}
void dequeue(){
    cout<<"Note: press 1 at place of value for deleting data from the queue otherwise press 0:"<<endl;
    int value;
    cout<<"enter value:";
    cin>>value;
    while(value!=0){
        if(value==1){
            temp=front;
        if(front==0 && rear==0){
            cout<<"empty queue"<<endl;
        }
        else if(front==rear){
            front=rear=0;
            free(temp);
        }
        else{
            front=front->next;
            rear->next=front;
            free(temp);
        }
        cout<<"enter value:";
        cin>>value;
        }else{
            cout<<"enter valid number.";
        }
    }


}
void peek(){
    if(front==0 && rear==0){
        cout<<"empty queue"<<endl;
    }
    else{
        cout<<"the peek element of the queue is:"<<front->data<<endl;
    }
}
};

int main(){
    Queue l1;
    int choice;
    cout<<"note:if do you want to exit from the loop then enter any invalide choice.\n";
    cout<<"enter choice:\n1.enqueue\n2.dequeue\n3.prints\n4.peek\n";
    do{
    cout<<"enter the value of choice:";
    cin>>choice;
    switch(choice)
    {
        case 1:
        l1.enqueue();
        break;
        case 2:
        l1.dequeue();
        break;
        case 3:
        l1.prints();
        break;
        case 4:
        l1.peek();
        break;
        default:
        cout<<"invalide choice:\n";
    }

    }while(choice>=1&&choice<=4);
    
}