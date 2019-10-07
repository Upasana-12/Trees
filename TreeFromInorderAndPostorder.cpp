/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int search(vector<int> &A, int s, int e, int num)
{
    int i;
    for(i=s;i<=e;i++)
    {
        if(A[i]==num)
        return i;
    }
}
TreeNode* util(vector<int> &A, vector<int>& B, int ins, int ine, int* posti)
{
    if(ins>ine)
    return NULL;
    TreeNode* temp=new TreeNode(B[*posti]);
    (*posti)--;
    if(ins==ine)
    return temp;
    int inorderi=search(A,ins,ine,temp->val);
    temp->right=util(A,B,inorderi+1,ine,posti);
    temp->left=util(A,B,ins,inorderi-1,posti);
    return temp;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) 
{
    int posti=B.size()-1;
   return util(A,B,0,A.size()-1,&posti);
}
