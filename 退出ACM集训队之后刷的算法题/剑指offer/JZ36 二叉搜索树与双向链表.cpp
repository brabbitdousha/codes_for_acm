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
    TreeNode* Convert(TreeNode* pRootOfTree) {
        TreeNode* pre=NULL;
        if(pRootOfTree==NULL) return NULL;
        doit(pRootOfTree,pre);
        TreeNode* res=pRootOfTree;
        while(res->left)
            res=res->left;
        return res;
    }
    
    void doit(TreeNode* u,TreeNode*& pre)
    {
        if(u==NULL) return;
        doit(u->left,pre);
        u->left=pre;
        if(pre!=NULL) pre->right=u;
        
        pre=u;
        doit(u->right,pre);
    }
};