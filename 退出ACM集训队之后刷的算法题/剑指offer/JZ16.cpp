/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
       if(pHead1==NULL)
       {
           return pHead2;
       }
       else if(pHead2==NULL)
       {
           return pHead1;
       }
        ListNode *preHead = new ListNode(-1);
    ListNode *node = preHead;
        
        while((pHead1!=NULL)&&(pHead2!=NULL))
        {
            if(pHead1->val<=pHead2->val)
            {
                node->next=pHead1;
                pHead1=pHead1->next;
            }
            else
            {
                node->next=pHead2;
                pHead2=pHead2->next;
            }
            node=node->next;
        }
        
        if(pHead1!=NULL) {node->next=pHead1;}
        else if(pHead2!=NULL) {node->next=pHead2;}
        
       return preHead->next;
    }
};