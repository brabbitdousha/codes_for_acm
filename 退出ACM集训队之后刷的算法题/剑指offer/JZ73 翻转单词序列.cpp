class Solution {
public:
    string ReverseSentence(string str) {
        string a;
        a=str+' ';
        stack<string> sta;
        string now="";
        for(int i=0;i<str.size();)
        {
            if(str[i]!=' ')
            {
                while(str[i]!=' '&&i<str.size())
                {
                    now+=str[i];
                    i++;
                }
                sta.push(now);
            }
            else
            {   now="";
                i++;
            }
        }
        string ans="";
        int ct=sta.size()-1;
        while(!sta.empty())
        {
            string now=sta.top(); sta.pop();
            ans+=now;
            ct--;
            if(ct>=0)
            {
                ans+=' ';
            }
        }
        return ans;
    }
};