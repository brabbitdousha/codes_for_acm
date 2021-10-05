class Solution {
public:
ListNode *ReverseList(ListNode* pHead) 


{
   ListNode* h=pHead;
    ListNode* pre=NULL;
    ListNode* nxt=pHead->next;
    
    while(h!=NULL)
    {
        h->next=pre;
        pre=h;
        h=nxt;
        nxt=h->next;
    }
    return pre;
    
    
}    
};