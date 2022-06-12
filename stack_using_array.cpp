#include<iostream>
using namespace std;
int stack[100],N=100,top=-1;
void display();
void push();
void pop();
void peek();
void full();
void empty();

int main()
{
    int choice;
    cout<<"note:if do you want to exit from the loop then enter any invalide choice.\n";
    cout<<"enter choice:\n1.push\n2.pop\n3.peek\n4.display\n5.empty\n6.full\n";
    do{
    cout<<"enter the value of choice:";
    cin>>choice;
    switch(choice)
    {
        case 1:
        push();
        break;
        case 2:
        pop();
        break;
        case 3:
        peek();
        break;
        case 4:
        display();
        break;
        case 5:
        empty();
        break;
        case 6:
        full();
        break;
        default:
        cout<<"invalide choice:\n";
    }

    }while(choice>=1&&choice<=6);
    
}
void display()
{
    int i;
    if(top==-1)
    {
        cout<<"stack is empty.\n";
    }
    else{
    cout<<"data in stack is:\n";
    for(i=top;i>=0;i--)
    {
        cout<<"%d ",stack[i];
    }
    cout<<"\n";
  }
    
}

void push()
{
    int x;
    cout<<"enter the value of data:";
    cin>>x;
    if(top==N-1)
    {
        cout<<"overflow condtion:\n";
    }
    else
    {
        top++;
        stack[top]=x;
    }
}
void pop()
{
    if(top==-1)
    {
        cout<<"undderflow condition.\n";
    }
    else{
        int x=stack[top];
        cout<<"the removing element from the stack is %d"<<x;
        top--;
        cout<<"\n";
    }
}
void peek()
{
    if(top==-1)
    {
        cout<<"underflow condition.\n";
    }
    else{
        cout<<"the top element of the stack is %d"<<stack[top];
        cout<<endl;
    }
}
void full()
{
    if(top==N-1)
    {
        cout<<"entire stack is full.\n";
    }
    else{
        cout<<"stack is not full.\n";
    }
}
void empty()
{
    if(top==-1)
    {
        cout<<"stack is empty.\n";
    }
    else{
        cout<<"stack is not empty.\n";
    }
}