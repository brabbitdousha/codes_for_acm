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
    
    void bfs(vector<vector<int> > & ans,TreeNode* u)
    {
        if(u==NULL) return;
        queue<TreeNode*> que; que.push(u);
        map<TreeNode*,int> num;
        num[u]=1;
      
        vector<int> G[1600];
        
        int cnt=1;
        G[cnt].push_back(u->val);
        while(!que.empty())
        {
            TreeNode* now=que.front(); que.pop();
            if(now->left!=NULL)
            {
                num[now->left]=num[now]+1;  
             cnt=max(cnt,num[now->left]);  
             que.push(now->left);
                G[num[now->left]].push_back(now->left->val);
            }
            if(now->right!=NULL)
            {
                num[now->right]=num[now]+1; 
             cnt=max(cnt,num[now->right]); 
             que.push(now->right);
                G[num[now->right]].push_back(now->right->val);
            }
            
        }
        
        for(int i=1;i<=cnt;i++)
        {   vector<int> temp=G[i];
            if(i%2==0) 
            {
                vector<int> temp2;
                for(int j=temp.size()-1;j>=0;j--)
                {
                    temp2.push_back(temp[j]);
                }
                ans.push_back(temp2);
            }
         else
         {
             ans.push_back(temp);
         }
         
        }
        
    }
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > ans;
        bfs(ans,pRoot);
        return ans;
    }
    
};
