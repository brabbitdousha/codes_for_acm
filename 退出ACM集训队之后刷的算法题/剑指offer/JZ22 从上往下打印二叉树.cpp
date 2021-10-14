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
    void bfs(vector<int> & G,TreeNode* s)
    {
        queue<TreeNode*> que;
        que.push(s);
        while(!que.empty())
        {
            TreeNode* now=que.front(); que.pop();
            G.push_back(now->val);
            if(now->left!=NULL)
            {
                que.push(now->left);
            }
            if(now->right!=NULL)
            {
                que.push(now->right);
            }
          
        }
    }
    vector<int> PrintFromTopToBottom(TreeNode* root) {
              
             vector<int> ans;
           if(root==NULL) return ans;
             bfs(ans,root);
        return ans;
    }
};