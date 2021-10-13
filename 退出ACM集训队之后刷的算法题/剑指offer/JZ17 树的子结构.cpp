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
    static TreeNode* temp;
    static bool flag;
    void gethead(TreeNode* u, TreeNode* v)
    {   if(u==NULL) return;
        if(u->val==v->val) {temp=u; if(check(temp,v)) flag=true;}
         gethead(u->left,v);
         gethead(u->right,v);
    }
    bool check(TreeNode* u,TreeNode* v)
    {
        
        
        if(v==NULL) return true;
        if(u==NULL) return false;
        
        if(u->val!=v->val) return false;
        
        return check(u->left,v->left)&&check(u->right,v->right);
        return false;
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if(pRoot2==NULL) return false;
        else if(pRoot1==NULL) return false;
        gethead(pRoot1,pRoot2);
        if(temp->val==-1){return false;}
       
        if(flag) return true;
        else return false;
    }
};
TreeNode* Solution:: temp=new TreeNode(-1);
bool Solution:: flag=false;