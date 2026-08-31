/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head||!head->next||!head->next->next)return {-1,-1};
        int f=-1;
        int pc=-1;
        int md=INT_MAX;

        ListNode *prev=head;
        ListNode *curr=head->next;
        int idx=1;

        while(curr->next!=NULL){
            ListNode *nxt = curr->next;
            bool ismax = (curr->val>prev->val&&curr->val>nxt->val);
            bool ismin = (curr->val<prev->val&&curr->val<nxt->val);
            if(ismax||ismin){
                if(f==-1)f=idx;
                else md=min(md,idx-pc);
                pc=idx;
            }
            prev=curr;
            curr=nxt;
            idx++;
        }
        if(f==pc)return {-1,-1};
        int maxdis=pc-f;
        return {md,maxdis};
    }
};