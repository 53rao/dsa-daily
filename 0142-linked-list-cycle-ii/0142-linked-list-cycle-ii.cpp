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
    ListNode *detectCycle(ListNode *head) {
        ListNode* one=head;
        if(!head||!head->next)
            return NULL;
        one=one->next;
        ListNode* two=(head->next)->next;
        while(one&&two){
            if(one==two){
                one =head;
                break;
            }
            one=one->next;
            two=two->next;
            if(two)
                two=two->next;
        }
        if(one==head){
            while(one&&two){
            if(one==two)
                return one;
                one=one->next;
                two=two->next;
            }
        }
        return NULL;
    }
};