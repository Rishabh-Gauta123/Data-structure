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
node *newnode,*temp,*top=0;//in the stack we are using head but in case of the stack we will use top instead of head or you can also use head
void push(){               // it's your wish.
int value;
cout<<"Note:for inserting data in the stack press 1 at the place of value otherwise press 0. "<<endl;
cout<<"enter value: ";
cin>>value;
while(value!=0){
      if(value==1){
          
    cout<<"enter data:";
    newnode=new node;
    cin>>newnode->data;
    newnode->next=top;
    top=newnode;
    cout<<"enter value: ";
    cin>>value;
    }
    else{
        cout<<"you did not press correct key."<<endl;
        break;
    }
      }

  }
  void display(){
    temp=top;
    int k=0;
    if(top==0){
        cout<<"Sorry,No Data in tha Stack.";
    }else{
        cout<<"data of the stack is:";
        while(temp!=0){
        cout<<temp->data<<" ";
        temp=temp->next;
        k++;
    }
    }
    cout<<endl;
    cout<<"the size of the stack is:"<<k;
    cout<<endl;
}
void peek(){
    if(top==0){
        cout<<"Empty stack."<<endl;
    }else{
        cout<<"The topmost element of the stack is:"<<top->data<<endl;
    }
}
void empty(){
    if(top==0){
        cout<<"Stack is empty."<<endl;
    }else{
        cout<<"stack is not empty."<<endl;
    }
}
void pop(){
    temp=top;
    int value;
    cout<<"Note:for removing data from the stack press 1 at the place of value otherwise press 0. "<<endl;
    cout<<"enter value: ";
    cin>>value;
    while(value!=0){
      if(value==1){
         if(top==0){
        cout<<"underflow condition.";
    }
    else{
        top=top->next;
        free(temp);
    }     
    
    cout<<"enter value: ";
    cin>>value;
    }
    else{
        cout<<"you did not press correct key."<<endl;
        break;
    }
      }
}

};

int main(){

    LinkList l1;
    int choice;
    cout<<"\n1.Push";
    cout<<"\n2.Pop";
    cout<<"\n3.peek";
    cout<<"\n4.display";
    cout<<"\n5.empty";
    cout<<"enter choice from the above method:";
    cin>>choice;

switch(choice)
    {
        case 1:
        l1.push();
        l1.display();
        break;
        case 2:
        l1.pop();
        l1.display();
        break;
        case 3:
        l1.peek();
        break;
        case 4:
        l1.display();
        break;
        case 5:
        l1.empty();
        break;
        default:
        cout<<"Please, select a valid choice.";
   }
}
