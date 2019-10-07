#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
struct node 
{ 
    int data; 
    struct node* left; 
    struct node* right; 
}; 
  
int height(node* root)
{
    if(root==NULL)
    return 0;
    return 1+max(height(root->left),height(root->right));
}
 int dia(node* root)
 {
     if(root==NULL)
     return 0;
     int lh=height(root->left);
     int rh=height(root->right);
     int ld=dia(root->left);
     int rd=dia(root->right);
     int a=max(lh+rh+1,max(ld,rd));
     return a;
 }
node* newNode(int data) 
{ 
    node* temp = new node; 
    temp->data = data; 
    temp->left = NULL; 
    temp->right = NULL; 
  
    return (temp); 
} 
int main() 
{ 
    struct node *root = newNode(1); 
    root->left        = newNode(2); 
    root->right       = newNode(3); 
    root->left->left  = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left  = newNode(6); 
    root->right->right = newNode(7); 
  
    int d=dia(root);
    cout<<d;
    return 0; 
} 