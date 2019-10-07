/*
Sample Input

        1
       / \
      2    3
     / \  /
    4  5 6
Sample Output

       1
      / \
     3   2
     \  / \
      6 5  4

3 6 1 5 2 4
*/

/* struct Node {
  int data;
  struct Node *left, *right;
};
The above structure is used for tree node. */
void util(struct Node* root)
{
  if(root==NULL)
    return ;
  struct Node* temp;
  util(root->left);
  util(root->right);
  temp=root->left;
  root->left=root->right;
  root->right=temp;
  
}
void inorder(struct Node* root)
{
  if(root==NULL)
    return;
  inorder(root->left);
  printf("%d ",root->data);
  inorder(root->right);
}
void findMirror(struct Node* root)
{
  if(root==NULL)
    return;
	util(root);
  //inorder(root);
}
