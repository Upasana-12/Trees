/* struct Node {
  int data;
  struct Node *left, *right;
};
The above structure is used for tree node and the function below is also provided to build a new node with given data. 
struct Node* newNode(int data);
*/
struct Node* util(int t[], struct Node* root, int i, int n)
{
  if(i<n)
  {
    //struct Node* temp=newNode(t[i]);
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=t[i];
    temp->left=NULL;
    temp->right=NULL;
    root=temp;
    root->left=util(t, root->left, 2*i+1, n);
    root->right=util(t, root->right, 2*i+2, n);
  }
  return root;
}
struct Node* buildTree(int t[], int n)
{
  if(n==0)
    return NULL;
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  // Complete the function body
//   node->data=t[0];
//   node->left=NULL;
//   node->right=NULL;
    node=util(t, node, 0, n);
  
  return node;
}