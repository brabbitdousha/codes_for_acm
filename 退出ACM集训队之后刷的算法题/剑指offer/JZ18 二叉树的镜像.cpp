/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pRoot TreeNode类 
     * @return TreeNode类
     */
    void dfs(TreeNode* u)
    {
        if(u==NULL) return;
        dfs(u->left);
        dfs(u->right);
        TreeNode* temp=u->left;
        u->left=u->right;
        u->right=temp;
    }
    TreeNode* Mirror(TreeNode* pRoot) {
        // write code here
        TreeNode* h=pRoot;
        dfs(h);
        return h;
    }
};