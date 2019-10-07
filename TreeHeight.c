/* struct Node {
  int data;
  struct Node *left, *right;
};
The above structure is used for tree node. */

int treeHeight(struct Node* t1)
{
	if(t1==NULL)
      return -1;
  int lh=treeHeight(t1->left);
   int rh=treeHeight(t1->right);
  if(lh>rh)
    return lh+1;
  else
    return rh+1;
}
