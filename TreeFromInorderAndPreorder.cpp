/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int search(vector<int> &B, int s, int e, int num)
{
    int i;
    for(i=s;i<=e;i++)
    {
        if(B[i]==num)
        return i;
    }
}
TreeNode* util(vector<int> &A, vector<int> &B, int ins, int ine, int *prei)
{
    if(ins>ine)
    return NULL;
    TreeNode* temp=new TreeNode(A[*prei]);
    (*prei)++;
    if(ins==ine)
    return temp;
    int inorderi=search(B,ins,ine,temp->val);
    temp->left=util(A,B,ins,inorderi-1,prei);
    temp->right=util(A,B,inorderi+1,ine,prei);
    return temp;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) 
{
    int prei=0;
    return util(A,B,0,A.size()-1,&prei);
}
