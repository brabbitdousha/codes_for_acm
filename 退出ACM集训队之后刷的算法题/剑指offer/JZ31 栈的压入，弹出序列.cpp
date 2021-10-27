class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> sta;
        queue<int> que;
        for(auto it:popV)
            que.push(it);
        for(auto it:pushV)
        {
            int now=it;
            sta.push(now);
            if(sta.top()==que.front())
            {  while(!sta.empty()&&!que.empty()&&sta.top()==que.front())
               {sta.pop();
                que.pop();
               }
            }
            
        }
        if(sta.empty()&&que.empty()) return true;
        else return false;
    }
};