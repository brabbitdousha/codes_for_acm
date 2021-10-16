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
    string s;
    int index=0;
    void ser(TreeNode* root,string& s)
    {
        if(root==NULL)
        {
            s+='#';
            s+=',';
            return;
        }
        s+=to_string(root->val);
        s+=',';
        ser(root->left,s);
        ser(root->right,s);
    }
    char* Serialize(TreeNode *root) {    
        ser(root,s);
        //cout<<"here: "<<s;
        return const_cast<char*>(s.c_str());
    }
    
    
    TreeNode* Deserialize(char *str) {
      
        string data(str);
        index=0;
        return des(data);
    }
      TreeNode* des(string& s)
      {
          if(index==s.size()||index>s.size())
          {
              return NULL;
          }
          if(s[index]=='#')
          {
              index++;
              index++;
              return NULL;
          }
          int sum=0;
          while(s[index]!=','&&index<s.size())
          {
              sum=sum*10+s[index]-'0';
              index++;
          }
          index++;
          TreeNode* root=new TreeNode(sum);
          root->left=des(s);
          root->right=des(s);
          return root;
          
      }
};