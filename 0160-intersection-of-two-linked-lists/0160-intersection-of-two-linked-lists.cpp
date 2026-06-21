/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        vector<ListNode*> a;
        vector<ListNode*> b;
        ListNode* curr=headA;
        while(curr){
            a.emplace_back(curr);
            curr=curr->next;
        }
        curr=headB;
        while(curr){
            b.emplace_back(curr);
            curr=curr->next;
        }
        int j=b.size()-1,i=a.size()-1;
        ListNode* prev=NULL;
        while(j>=0&&i>=0){
            if(a[i]==b[j]){
                prev=a[i];
                i--;
                j--;
            }
            else
                return prev;
        }
        return prev;

    }
};