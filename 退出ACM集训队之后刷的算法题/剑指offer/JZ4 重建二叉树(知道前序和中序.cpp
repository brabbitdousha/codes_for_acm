/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* dfs(int pl,int pr,int vl,int vr,vector<int>& pre,vector<int>& vin)
    {
        if(pl==pr) return new TreeNode(pre[pl]);
        if(pl>pr) return NULL;
        
        TreeNode* root=new TreeNode(pre[pl]);
        int index=0;
        for(int i=vl;i<=vr;i++)
        {
            if(vin[i]==root->val)
            {
                index=i;
                break;
            }
        }
        
        int leftlen= index-vl;
        int rightlen= vr-index;
        if(leftlen>0) root->left=dfs(pl+1,pl+leftlen,vl,index-1,pre,vin);
        if(rightlen>0) root->right=dfs(pl+leftlen+1,pr,index+1,vr,pre,vin);
        return root;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
          TreeNode* root=dfs(0,pre.size()-1,0,vin.size()-1,pre,vin);
        return root;
    }
};