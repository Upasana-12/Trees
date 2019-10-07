/*
Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, then right to left for the next level and alternate between).

Example :
Given binary tree

    3
   / \
  9  20
    /  \
   15   7
return

[
         [3],
         [20, 9],
         [15, 7]
]
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) 
{
    vector<vector<int>> res;
    vector<int> v;
    stack<TreeNode*> s1,s2;
    if(A==NULL)
    return res;
    s1.push(A);
    while(!s1.empty() || !s2.empty())
    {
        while(!s1.empty())
        {
            TreeNode* temp=s1.top();
            s1.pop();
            v.push_back(temp->val);
            if(temp->left)
            s2.push(temp->left);
            if(temp->right)
            s2.push(temp->right);
        }
        if(v.size()!=0)
        res.push_back(v);
        v.clear();
        while(!s2.empty())
        {
             TreeNode* temp=s2.top();
            s2.pop();
            v.push_back(temp->val);
            if(temp->right)
            s1.push(temp->right); 
            if(temp->left)
            s1.push(temp->left);
            
        }
        if(v.size()!=0)
        res.push_back(v);
        v.clear();
    }
    return res;
}
