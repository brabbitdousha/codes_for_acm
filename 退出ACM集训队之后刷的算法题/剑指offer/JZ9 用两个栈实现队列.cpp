class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.empty())
        {
        while(!stack1.empty())
        {
            int now=stack1.top();
            stack1.pop();
            stack2.push(now);
        }
        }
         int now=stack2.top();
        stack2.pop();
        return now;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};