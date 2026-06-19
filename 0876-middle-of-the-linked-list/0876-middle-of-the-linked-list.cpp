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
    ListNode* middleNode(ListNode* head) {
        ListNode* mid=head;
        ListNode* end=head->next;
        while(end){
            mid=mid->next;
            end=end->next;
            if(end)
                end=end->next;
        }
        if(end)
            return mid->next;
        else
            return mid;
        
    }
};