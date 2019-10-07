/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* util(TreeNode* A, int B, int C)
{
        if(A==NULL)
    return NULL;
    if(A->val==B || A->val==C)
    return A;
    TreeNode* l=util(A->left,B,C);
    TreeNode* r=util(A->right,B,C);
    if(l && r)
    return A;
    if(l)
    return l;
    if(r)
    return r;
    return NULL;
}
bool find(TreeNode* root, int val)
{
    if (!root)
        return false;
    if (root->val == val)
        return true;
    if ((root->left && find(root->left, val)) || 
        (root->right && find(root->right, val)))
        return true;
    return false;
}
int Solution::lca(TreeNode* A, int B, int C) 
{
    if(A==NULL)
    return -1;
        if (!find(A, B) || !find(A, C))
        return -1;
    TreeNode* n = util(A,B,C);
    if(n==NULL)
    return -1;
    return n->val;    
}

