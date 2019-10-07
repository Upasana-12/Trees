/* struct Node
{
  int data;
  struct Node *left, *right;
};
The above structure is used for tree node 	*/
struct Node* insert(struct Node* root, int data)
{
    if(root==NULL)
    {
      struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
      temp->data=data;
      temp->left=NULL;
      temp->right=NULL;
      root=temp;
    }
    else if(data<=root->data)
    {
      root->left=insert(root->left,data);
    }
    else
    {
      root->right=insert(root->right,data);
    }
    return root;
  
}
struct Node* buildSearchTree(int t[], int n)
{
  if(n==0)
    return NULL;
    struct Node* root = NULL;
    // Complete the function body.
  for(int i=0;i<n;i++)
	root=insert(root,t[i]);
    return(root);
}
