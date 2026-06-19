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
    bool hasCycle(ListNode *head) {
        ListNode* one=head;
        if(!head||!head->next)
            return false;

        ListNode* two=(head->next)->next;
        while(one&&two){
            if(one==two){
                return true;
            }
            one=one->next;
            two=two->next;
            if(two)
                two=two->next;
        }
        return false;
    }
};