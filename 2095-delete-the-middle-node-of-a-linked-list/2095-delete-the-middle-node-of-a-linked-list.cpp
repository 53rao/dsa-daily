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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* mid=head;
        ListNode* prev;
        ListNode* end=head;
        while(end&&end->next){
            prev=mid;
            mid=mid->next;
            end=end->next;
            if(end)
                end=end->next;
        }
        if(!prev){
            return head->next;
        }
        else{
            
            prev->next=mid->next;
            return head;
        }
    }
};