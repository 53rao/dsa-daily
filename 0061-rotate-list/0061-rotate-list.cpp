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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* one=head;
        ListNode* two=head;
        ListNode* soln;
        int count=0;
        if(!k||!head)
            return head;
        while(two){
            count++;
            two=two->next;
        }
        k=k%count;
        count=0;
        two=head;
        while(two->next){
            if(count<k){
                two=two->next;
                count++;
            }
            else{
                one=one->next;
                two=two->next;
            }
        }
        two->next=head;
        soln=one->next;
        one->next=NULL;
        return soln;
    }
};