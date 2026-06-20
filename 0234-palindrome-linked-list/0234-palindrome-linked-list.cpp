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
    bool isPalindrome(ListNode* head) {
        vector<int> dummy;
        int n;
        ListNode* curr=head;
        while(curr){
            dummy.emplace_back(curr->val);
            curr=curr->next;
        }
        n=dummy.size();
        for(int i=0;i<n/2;i++){
            if(dummy[i]!=dummy[n-i-1])
                return false;
        }
        return true;
    }
};