#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node *creat()
{
    int x;
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data(-1 for no node):");
    scanf("%d",&x);
    if(x==-1){
        return 0;
    }
    else{
        newnode->data=x;
        printf("enter left child of %d",x);
        printf("\n");
        newnode->left=creat();
        printf("enter right child of the %d",x);
        printf("\n");
        newnode->right=creat();
        return newnode;
    }
}
int main(){
    struct node *root;
    root=0;
    root=creat();
}