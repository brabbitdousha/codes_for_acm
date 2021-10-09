/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/


/*快慢指针法，快指针一次走两步，慢指针一次走一步，
当快慢指针第一次相遇时2（x+y）=n圈周长+x+y
所以 x+y=n圈周长
x是到环之前的距离， y是在环上走的距离。

所以 走到y的人再走一个 x。就是n*环长 
起点人走一个x，就可以彼此相遇 
即当快指针回到head和慢指针以同样速度每次走一步，最终会在链表中环的入口结点处相
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
         ListNode *fast=pHead;
        ListNode *low=pHead;
        while((fast->next)&&(fast))
        {
            fast=fast->next->next;
            low=low->next;
            if(fast==low) break;
        }
        if((!fast)||(!fast->next)) return NULL;
        
        low=pHead;
        while(low!=fast)
        {
            low=low->next;
            fast=fast->next;
        }
        return low;
    }
};
