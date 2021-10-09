/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
     static int ans;
     void dfs(TreeNode* u,int cnt)
     {   ans=max(ans,cnt);
         if(u->left!=NULL)
         {
             dfs(u->left,cnt+1);
         }
         if(u->right!=NULL)
         {
             dfs(u->right,cnt+1);
         }
     }
    int TreeDepth(TreeNode* pRoot) {
          if(pRoot==NULL) return 0;
           dfs(pRoot,1);
        return ans;
    }
};
int Solution::ans=0;
