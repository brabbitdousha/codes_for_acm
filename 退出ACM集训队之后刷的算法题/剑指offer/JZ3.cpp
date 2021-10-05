/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> ans;
        while(head!=NULL)
        {
            ans.push_back(head->val);
            head=head->next;
        }
        int last=ans.size();
        for(int i=0;i<ans.size()/2;i++)
        {   //printf("here!\n");
            last--;
            int t=ans[i];
            ans[i]=ans[last];
            ans[last]=t;
          //  if(last==i) break;
        }
        return ans;
    }
};