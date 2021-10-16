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
       void bfs(TreeNode* s, vector<vector<int> > &ans)
       {
           int cnt=1;
           vector<int> G[1500];
           map<TreeNode*,int> mp;
           mp[s]=1;
           G[cnt].push_back(s->val);
           queue<TreeNode*> que;
           que.push(s);
           while(!que.empty())
           {
               TreeNode* now=que.front(); que.pop();
               if(now->left!=NULL)
               {
                   mp[now->left]=mp[now]+1;
                   cnt=max(cnt,mp[now->left]);
                   G[mp[now->left]].push_back(now->left->val);
                   que.push(now->left);
               }
               if(now->right!=NULL)
               {
                   mp[now->right]=mp[now]+1;
                   cnt=max(cnt,mp[now->right]);
                   G[mp[now->right]].push_back(now->right->val);
                    que.push(now->right);
               }
           }
           for(int i=1;i<=cnt;i++)
           {   vector<int> temp;
               for(int j=0;j<G[i].size();j++)
               {
                   int to=G[i][j];
                   temp.push_back(to);
               }
              ans.push_back(temp);
           }
       }
        vector<vector<int> > Print(TreeNode* pRoot) {
          vector<vector<int> > ans;
              if(pRoot==NULL) return ans;
               bfs(pRoot,ans);
            return ans;
        }
    
};