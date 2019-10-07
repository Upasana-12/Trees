#include<bits/stdc++.h>
using namespace std;
struct node 
{ 
    int data; 
    struct node* left; 
    struct node* right; 
}; 
void reverseLevelOrder(node* root)
{
    stack <node *> s; 
    queue <node *> q; 
    q.push(root); 

    while (!q.empty()) 
    { 
        /* Dequeue node and make it root */
        root = q.front(); 
        q.pop(); 
        s.push(root); 
  
        /* Enqueue right child */
        if (root->right) 
            q.push(root->right); // NOTE: RIGHT CHILD IS ENQUEUED BEFORE LEFT 
  
        /* Enqueue left child */
        if (root->left) 
            q.push(root->left); 
    } 
  
    // Now pop all items from stack one by one and print them 
    while (!s.empty()) 
    { 
        root = s.top(); 
        cout << root->data << " "; 
        s.pop(); 
    }  
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
  
    cout << "Reverse Level Order traversal of binary tree is \n"; 
    reverseLevelOrder(root); 
  
    return 0; 
} 