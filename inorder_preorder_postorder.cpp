#include<iostream>
using namespace std;
struct node*create();
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);

int main()
{
    struct node *root;
    root=0;
    root=create();
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;

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
void inorder(struct node *root)
{
    if(root==0)
    {
        return ;
    }
    else
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
void preorder(struct node *root)
{
    if(root==0)
    {
        return ;
    }
    else
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    
}
void postorder(struct node *root)
{
    if(root==0)
    {
        return ;
    }
    else
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }

}
