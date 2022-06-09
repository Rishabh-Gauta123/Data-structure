#include<iostream>
#include<string>
#include<cmath>
using namespace std;

struct node{
    int data;
    node *next;
};

class LinkList{
public:
node *head,*newnode,*temp,*prevnode,*nextnode;
void create(){
head=0;
int value,i;
i=0;
cout<<"Note:for inserting data in the link list press 1 at the place of value otherwise press 0. "<<endl;
cout<<"enter value: ";
cin>>value;
while(value!=0){
      if(value==1){
          
    cout<<"enter data:";
    newnode=new node;
    cin>>newnode->data;
    if(head==0){
        head=temp=newnode;
    }else{
        temp->next=newnode;
        temp=newnode;
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
    temp=head;
    int k=0;
    if(head==0){
        cout<<"Sorry,No Data in tha LinkList";
    }else{
        cout<<"data of the linklist is:";
        while(temp!=0){
        cout<<temp->data<<" ";
        temp=temp->next;
        k++;
    }
    }
    cout<<endl;
    cout<<"the size of the link list is:"<<k;
    cout<<endl;
}
void insert_fp(){
    cout<<"Note: press 1 at place of value for adding value on first place otherwise press 0:"<<endl;
    int value;
    cout<<"enter value:";
    cin>>value;
    while(value!=0){
        if(value==1){
            newnode=new node;
            cout<<"enter value which you want to insert:";
            cin>>newnode->data;
            newnode->next=head;
            head=newnode;
            prints();
            cout<<"enter value:";
            cin>>value;
        }else{
            cout<<"enter valid number.";
        }
    }
    cout<<"you inserted data succesfully in the link list.";

}
};

int main(){
    int size;
    LinkList l1;
    l1.create();
    l1.prints();
    l1.insert_fp();
    
}