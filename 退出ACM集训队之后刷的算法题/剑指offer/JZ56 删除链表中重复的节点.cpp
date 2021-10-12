/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
             ListNode* h=new ListNode(-1);
             ListNode* p=pHead;
             h->next=pHead;
             ListNode* pre=h;
             while(p&&(p->next))
             {
                 if(p->val==p->next->val)
                 {
                     int x=p->val;
                     while(p&&(p->val==x))
                     {
                         p=p->next;
                     }
                     pre->next=p;
                 }
                 else
                 {   pre=p;
                     p=p->next;
                 }
             }
        return h->next;
    }
};