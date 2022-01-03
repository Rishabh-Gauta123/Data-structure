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
    printf("preorder is:");
    preorder(root);
    printf("\n");
    printf("inorder is:");
    inorder(root);
    printf("\n");
    printf("postorder is:");
    postorder(root);
    printf("\n");

}
void preorder(struct node *root){
    if(root==0){
        return 0;
    }
    else{
        printf(" %d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct node *root){
    if(root==0){
        return 0;
    }
    else{
        inorder(root->left);
        printf(" %d ",root->data);
        inorder(root->right);
    }
}
void postorder(struct node *root){
    if(root==0){
        return 0;
    }
    else{
        postorder(root->left);
        postorder(root->right);
        printf(" %d ",root->data);
    }
}