#include<iostream>
#define N 50
using namespace std;
void enqueue();
void display();
void dequeue();
void peek();
int rear=-1;
int front=-1;
int queue[N];
int main(){
    int choice;
    cout<<"note:if do you want to exit from the loop then enter any invalide choice.\n";
    cout<<"enter choice:\n1.enqueue\n2.dequeue\n3.peek\n4.display\n";
    do{
    cout<<"enter the value of choice:";
    cin>>choice;
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
    return 0;
    
}
void enqueue(){
    int data;
    cout<<"enter data which you want dequeue:";
    cin>>data;
    if(rear==N-1)
    {
        cout<<"overflow condition."<<endl;
    }
    else if(rear==-1 && front==-1)
    {
       rear=front=0; 
       queue[rear]=data;
    }
    else
    {
        rear=rear+1;
        queue[rear]=data;
    }
    cout<<endl;
    
}
void display(){
    int i;
    cout<<"data in the queue is:";
    if(rear==-1 && front==-1)
    {
        cout<<"Sorry, empty queue."<<endl;
    }
    else
    {
    for(i=front;i<=rear;i++){
        cout<<queue[i]<<" ";
     } 
    }
    cout<<endl;
}
void dequeue(){
    if(front==-1 && rear==-1)
    {
       cout<<"Sorry, underflow condition.\n";
    }
    else if(front==rear)
    {
       front=rear=-1;
    }
    else
    {
        front=front+1;
    }
    cout<<endl;
}
void peek(){
    if(rear==-1 && front==-1){
        cout<<"empty queue \n";
    }
    else{
        cout<<"peek data of the queue is:"<<queue[front]<<endl;
    }
}
