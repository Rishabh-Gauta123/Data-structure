#include<iostream>
using namespace std;
struct node*create();

int main()
{
    struct node *root;
    root=0;
    root=create();

}
struct node
{
    int data;
    node *left,*right;
};
struct node *create()
{
    int x;
    node *newnode;
    newnode=new node;
    cout<<"enter x (enter -1 for no node):";
    cin>>x;
    if(x==-1)
    {
        return 0;
    }
    else
    {
        newnode->data=x;
        cout<<"enter the left child of "<<x<<endl;
        newnode->left=create();
        cout<<"enter the right child of "<<x<<endl;
        newnode->right=create();
        return newnode;
    }

}
