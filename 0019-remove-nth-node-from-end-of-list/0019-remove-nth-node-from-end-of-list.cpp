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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* end=head;
        int count=1;
        while(end->next){
            if(count<n){
                end=end->next;
                count++;
            }
            else{
                prev=curr;
                curr=curr->next;
                end=end->next;
            }
            
        }
        if(curr==head){
            return head->next;
        }
        else{
            prev->next=curr->next;
            return head;
        }
        
    }
};