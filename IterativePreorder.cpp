/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* A) 
{
    vector<int> v;
    stack<TreeNode*> s;
    /*
    s.push(A);
    while(!s.empty())
    {
        TreeNode* temp=s.top();
        v.push_back(temp->val);
        s.pop();
        if(temp->right)
        s.push(temp->right);
        if(temp->left)
        s.push(temp->left);
    }
    */
    TreeNode* curr=A;
    while(curr!=NULL || !s.empty())
    {
        while(curr!=NULL)
        {
            v.push_back(curr->val);
            s.push(curr);
            curr=curr->left;
        }
        curr=curr->right;
        s.pop();
    }
    return v;
}
