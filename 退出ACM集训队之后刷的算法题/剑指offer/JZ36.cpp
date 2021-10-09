/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/


/*����й�����㣬��ôָ��һ���ߵ�ĩβ�Ĳ��֣�Ҳ��һ�����ص�����������ָ���·���ɡ�
p1�� 0-1-2-3-4-5-null(��ʱ����ifelse)-a-b-4-5-null
p2: a-b-4-5-null(��ʱ����ifelse)0-1-2-3-4-5-null
*/

class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
       if(pHead1==NULL||pHead2==NULL) return NULL;
        ListNode *p1=pHead1;
        ListNode *p2=pHead2;
        while(p1!=p2)
        {
            p1=p1->next;
            p2=p2->next;
            if(p1!=p2)
            {
                if(p1==NULL) p1=pHead2;
                if(p2==NULL) p2=pHead1;
            }
        }
        return p1;
    }
};
