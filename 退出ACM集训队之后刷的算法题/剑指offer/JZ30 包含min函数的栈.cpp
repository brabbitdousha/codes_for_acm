class Solution {
public:
    stack<int> sta;
    set<int> s;
    map<int,int> mark;
    void push(int value) {
        sta.push(value);
        mark[value]++;
        s.insert(value);
    }
    void pop() {
        int now=sta.top();
        sta.pop();
        mark[now]--;
        if(mark[now]==0) s.erase(now);
    }
    int top() {
        return sta.top();
    }
    int min() {
        int now=*s.begin();
        return now;
    }
};