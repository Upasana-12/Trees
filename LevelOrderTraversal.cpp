/*
Given binary tree

    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
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
vector<vector<int> > Solution::levelOrder(TreeNode* A) 
{
   queue<int> ql;
   queue<struct TreeNode*> qn;
    vector<int> v;
    vector<vector<int>> res;
    if(A==NULL)
    return res;
    ql.push(0);
    qn.push(A);
    while(!qn.empty())
    {
        struct TreeNode* temp=qn.front();
        int level=ql.front();
        qn.pop();
        ql.pop();
        if(ql.empty() || ql.front()!=level)
        {
            v.push_back(temp->val);
            res.push_back(v);
            v.clear();
        }
        else
        {
            v.push_back(temp->val);
        }
        if(temp->left)
        {
            qn.push(temp->left);
            ql.push(level+1);
        }
        if(temp->right)
        {
            qn.push(temp->right);
            ql.push(level+1);
        }
    }
    return res;
}
