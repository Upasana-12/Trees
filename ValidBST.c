#include<limits.h>
/* struct Node
{
  int data;
  struct Node *left, *right;
};
The above structure is used for tree node. */

int util(struct Node* root, int min, int max)
{
  if(root==NULL)
    return 1;
  if((root->data>min && root->data<max) && ((util(root->left,min,root->data)) && (util(root->right, root->data, max))))
    return 1;
  else
    return 0;
}
int isBinarySearchTree(struct Node* t1)
{
  if(t1==NULL)
    return 1;
	return util(t1,INT_MIN,INT_MAX);
}
