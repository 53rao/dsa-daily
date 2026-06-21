/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        vector<int> temp;
        Node* curr=head;
        while(curr){
            temp.emplace_back(curr->data);
            curr=curr->next;
        }
        sort(temp.begin(),temp.end());
        curr=head;
        int k=0;
        while(curr){
            curr->data=temp[k++];
            curr=curr->next;
        }
        return head;
    }
};