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
    void dfs(int cnt,TreeNode* last,TreeNode* u,map<TreeNode*,int> &dis,map<TreeNode*,TreeNode*> &pre,vector<TreeNode*> &ans)
    {
        if(u==NULL) return;
        if(last->val!=-2000)
        {
            dis[u]=dis[last]+u->val;
            pre[u]=last;
        }
        else
        {
            dis[u]=u->val;
             pre[u]=last;
        }
        if(dis[u]==cnt&&(u->left==NULL&&u->right==NULL))
        {
            ans.push_back(u);
        }
        if(u->left!=NULL) dfs(cnt,u,u->left,dis,pre,ans);
        if(u->right!=NULL)dfs(cnt,u,u->right,dis,pre,ans);
    }
    
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> > G;
         if(root==NULL) return G;
       map<TreeNode*,int> dis;
       map<TreeNode*,TreeNode*> pre;
       vector<TreeNode*> ans;
        TreeNode* last=new TreeNode(-2000);
        dfs(expectNumber,last,root,dis,pre,ans);
        if(ans.size()==0) return G;
        
        for(int i=0;i<ans.size();i++)
        {
            TreeNode* to=ans[i];
            //cout<<to->val<<endl;
            vector<int> temp1;
            while(to->val!=-2000)
            {
                temp1.push_back(to->val);
                to=pre[to];
            }
            vector<int> temp2;
            for(int j=temp1.size()-1;j>=0;j--)
            { // cout<<temp1[j]<<endl;
                temp2.push_back(temp1[j]);
            }
            G.push_back(temp2);
        }
        return G;
    }
};