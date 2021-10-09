/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/


/*����ָ�뷨����ָ��һ������������ָ��һ����һ����
������ָ���һ������ʱ2��x+y��=nȦ�ܳ�+x+y
���� x+y=nȦ�ܳ�
x�ǵ���֮ǰ�ľ��룬 y���ڻ����ߵľ��롣

���� �ߵ�y��������һ�� x������n*���� 
�������һ��x���Ϳ��Ա˴����� 
������ָ��ص�head����ָ����ͬ���ٶ�ÿ����һ�������ջ��������л�����ڽ�㴦��
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
