/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

注意在堆上创建
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if(pHead==NULL) return pHead;
        RandomListNode *newhead=new RandomListNode(-1);
        RandomListNode* newp=newhead;
        RandomListNode* p=pHead;
        
        while(p)
        {
             RandomListNode *temp=new RandomListNode(p->label);
             newp->next=temp;
             p=p->next;
             newp=newp->next;
        }
        
        newp=newhead->next;
        p=pHead;
        
        while(newp)
        {
            if(p->random==NULL) newp->random=NULL;
            else{
                RandomListNode* random=pHead;
                RandomListNode* newrandom=newhead->next;
                while(p&&p->random!=random)
                {
                    random=random->next;
                    newrandom=newrandom->next;
                }
                 newp->random=newrandom;
            }
            newp=newp->next;
            p=p->next;
        }
        
        return newhead->next;
    }
};