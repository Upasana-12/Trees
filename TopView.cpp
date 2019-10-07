#include<bits/stdc++.h>
using namespace std;
struct node 
{ 
    int data; 
    struct node* left; 
    struct node* right; 
}; 
  

  

void printVerticalOrder(node* root) 
{ 
    // Base case 
    if (!root) 
        return; 

    map < int,vector<int> > m; 
    int hd = 0; 

    queue<pair<node*, int> > q; 
    q.push(make_pair(root, hd)); 
  
     while (!q.empty()) 
     { 
        // pop from queue front 
        pair<node *,int> temp = q.front(); 
        q.pop(); 
        hd = temp.second; 
        node* n = temp.first; 
  
        if(m.count(hd)==0)
        m[hd].push_back(n->data); 
  
        if (n->left != NULL) 
            q.push(make_pair(n->left, hd-1)); 
        if (n->right != NULL) 
            q.push(make_pair(n->right, hd+1)); 
    } 
  
  
    map< int,vector<int> > :: iterator it; 
    for (it=m.begin(); it!=m.end(); it++) 
    { 
        for (int i=0; i<it->second.size(); ++i) 
            cout << it->second[i] << " "; 
        cout << endl; 
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
  
   printVerticalOrder(root);
  
    return 0; 
} 