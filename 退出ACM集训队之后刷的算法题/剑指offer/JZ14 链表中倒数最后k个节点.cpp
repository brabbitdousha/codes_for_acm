
/*
  让第一个先走k步
  然后它和第二个(从头开始走)  一起走。
  那么第二个就到了倒数第k个那里
*/
ListNode* FindKthToTail(ListNode* pHead, int k) {
        // write code here
        ListNode *first=pHead;
        for(int i=0;i<k;i++)
        {
            if(first==NULL) return first;
            first=first->next;
        }
        
        ListNode *last=pHead;
        
          while(first!=NULL)
          {
              first=first->next;
              last=last->next;
          }
        return last;
        
       
    }
};