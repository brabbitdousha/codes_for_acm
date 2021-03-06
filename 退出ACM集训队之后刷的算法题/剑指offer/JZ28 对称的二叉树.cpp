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
    bool isSymmetrical(TreeNode* pRoot) {
            if(pRoot==NULL)
                return true;
          return f(pRoot->left,pRoot->right);
    }
    
    bool f(TreeNode *t1,TreeNode *t2)
    {
        if(t1==NULL&&t2==NULL) return true;
        
        if(t1!=NULL&&t2!=NULL)
        {
            return t1->val==t2->val&&f(t1->left,t2->right)&&f(t1->right,t2->left);
        }
        return false;
    }

};