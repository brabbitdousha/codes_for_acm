/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    void dfs(TreeNode* u,vector<TreeNode*> &G)
    {   if(u==NULL) return;
        dfs(u->left,G);
        G.push_back(u);
        dfs(u->right,G);
    }
    TreeNode* KthNode(TreeNode* pRoot, int k) {
        vector<TreeNode*> G;
        dfs(pRoot,G);
        
        int ct=0;
        if(k==0||G.size()==0) return NULL;
        if(k>G.size()) return NULL;
        for(int i=0;i<G.size();i++)
        {    ct++;
            TreeNode* to=G[i];
             if(ct==k) return to;
        }
        return NULL;
        
    }

    
};