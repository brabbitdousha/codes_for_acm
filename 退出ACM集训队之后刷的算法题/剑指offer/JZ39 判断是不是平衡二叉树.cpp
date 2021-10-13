class Solution {
public:
    static bool is_avi;
    int dfs(TreeNode* pRoot)
    {
        if(pRoot==NULL) return 0;
        int h1=0;
        int h2=0;
        if(pRoot->left!=NULL) h1=dfs(pRoot->left);
        if(pRoot->right!=NULL)h2=dfs(pRoot->right);
        if(abs(h1-h2)>1) is_avi=false;
        return max(h1,h2)+1;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot==NULL) return true;
        dfs(pRoot);
        if(is_avi) return true;
        else return false;
    }
};
bool Solution::  is_avi=true;