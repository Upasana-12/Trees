/*
Sample Input

        1
       / \
      2    3
     / \  /
    4  5 6
Sample Output

1 2 4 2
1 2 5 2
1 3 6 2
3
Explanation

First path is from 1 to 4 having 2 edges, so 1 2 4 is path and 2 is length of it. 
Similarly for other two leaf nodes. And at last line total number of paths are printed.
*/

/* struct Node
{
  int data;
  struct Node *left, *right;
};
The above structure is used for tree node. */
void print(struct Node* root, int arr[], int i,int* c)
{
  if(root==NULL)
  {
    return;
  }
  arr[i]=root->data;
  if(root->left==NULL && root->right==NULL)
  {
    for(int j=0;j<=i;j++)
    {
      printf("%d ",arr[j]);
    }
    printf("%d\n",i);
    (*c)++;
    i--;
    return;
  }
  print(root->left,arr,i+1,c);
  print(root->right,arr,i+1,c);
  i--;
}
void printAllPaths(struct Node* root) 
{
	if(root==NULL)
      return;
  int arr[10];
  int c=0;
  print(root,arr,0,&c);
  printf("%d",c);
}
