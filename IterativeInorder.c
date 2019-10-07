/* struct Node
{
  int data;
  struct Node *left, *right;
};
The above structure is used for tree node. */

struct Node* s[1000];
int t=-1;
int empty()
{
  if(t==-1)
    return 1;
  else 
    return 0;
}
void push(struct Node* n)
{
  s[++t]=n;
}
struct Node* top()
{
  return s[t];
}
void pop()
{
  if(t!=-1)
  {
    t--;
  }
}
void printInorder(struct Node* root)
{
	struct Node* curr=root;
  while(curr!=NULL || !empty())
  {
    while(curr!=NULL)
    {
      push(curr);
      curr=curr->left;
    }
    curr=top();
    pop();
    printf("%d ",curr->data);
    curr=curr->right;
  }
}
