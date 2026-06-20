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
    ListNode* oddEvenList(ListNode* head) {
        int i=0,j,k;
        vector<int> odd;
        vector<int> even;
        ListNode* curr=head;
        while(curr){
            i++;
            if(i%2==0){
                even.emplace_back(curr->val);
            }
            else{
                odd.emplace_back(curr->val);
            }
            curr=curr->next;
        }
        curr=head;
        i=0,j=0,k=0;
        while(curr){
            if(i<odd.size()){
                curr->val=odd[j++];
            }
            else{
                curr->val=even[k++];
            }
            i++;
            curr=curr->next;
        }
        return head;
    }
};