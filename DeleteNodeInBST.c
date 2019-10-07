/*  The structure of the tree is
struct tree_node
{
  int data;
  struct tree_node* left_child;
  struct tree_node* right_child;
}; */

struct tree_node* insert(struct tree_node* root, int key)
{
  if (root == NULL)
  {
    struct tree_node *temp =  (struct tree_node *)malloc(sizeof(struct tree_node));
    temp->data = key;
    temp->left_child = temp->right_child = NULL;
    printf("%d element is inserted in BST.\n",key);
    return temp;
  }

  if (key < root->data)
    root->left_child = insert(root->left_child, key);
  else if (key > root->data)
    root->right_child = insert(root->right_child, key);

  return root;
}

struct tree_node* minValueNode(struct tree_node* node)
{
  struct tree_node* current = node;

  while (current->left_child != NULL)
    // go deep in left, as inorder successor will be minimum of right subtree &
    // leftmost node of right subtree will be the inorder successor.
    current = current->left_child;

  return current;
}

struct tree_node* deleteNode(struct tree_node* root, int key)
{
  if (root == NULL)
  {
    printf("Node not found\n"); // Node not present in the tree so return NULL.
    return NULL;
  }

  // If the key to be deleted is smaller than the root's key
  if (key < root->data)
    root->left_child = deleteNode(root->left_child, key);

  // If the key to be deleted is greater than the root's key
  else if (key > root->data)
    root->right_child = deleteNode(root->right_child, key);

  // if key is same as root's key, then This is the node to be deleted
  else
  {
    struct tree_node *temp = NULL;
    // node with no child
    if (root->left_child == NULL && root->right_child == NULL)
    {
      free(root);
      return NULL;
    }
    else if(root->left_child == NULL)
    {
      temp = root->right_child;
      free(root);
      return temp;
    }
    else if (root->right_child == NULL)
    {
      temp = root->left_child;
      free(root);
      return temp;
    }
    // if none of above case execute then,
    // node is having with two children So,
    // Get the inorder successor or inorder predecessor
    temp = minValueNode(root->right_child); // inorder successor is taken here.

    // Copy the inorder successor's content to this node
    root->data = temp->data;

    // Delete the inorder successor
    root->right_child = deleteNode(root->right_child, temp->data);

    // Delete the inorder predecessor if it is taken above.
    // root->left_child = deleteNode(root->left_child, temp->data);
  }
  return root;
}

int main()
{
  // create the root tree_node
  struct tree_node *root = NULL;
  struct tree_node *temp;
  int key;

  root = insert(root, 25);
  insert(root, 15);
  insert(root, 50);
  insert(root, 10);
  insert(root, 22);
  insert(root, 35);
  insert(root, 70);

  printf("\nInorder traversal of binary search tree is \n");
  printInorder(root);

  key = 22;
  printf("\nDelete node with key = %d\n",key);
  root = deleteNode(root, key);
  printf("\nInorder traversal of binary search tree is \n");
  printInorder(root);

  key = 28;
  printf("\nDelete node with key = %d\n",key);
  root = deleteNode(root, key);
  printf("\nInorder traversal of binary search tree is \n");
  printInorder(root);

  key = 25;
  printf("\nDelete node with key = %d\n",key);
  root = deleteNode(root, key);
  printf("\nInorder traversal of binary search tree is \n");
  printInorder(root);

  return 0;
}
