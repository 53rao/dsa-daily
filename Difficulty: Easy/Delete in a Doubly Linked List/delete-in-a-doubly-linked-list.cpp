/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    Node* delPos(Node* head, int x) {
        // code here
        if(x==1){
            (head->next)->prev=nullptr;
            return head->next;
        }
        Node* curr=head->next;
        Node* prev=head;
        int k=1;
        while(curr){
            if(k==x-1){
                prev->next=curr->next;
                if(curr->next){
                    (curr->next)->prev=prev;
                }
                return head;
            }
            prev=curr;
            curr=curr->next;
            k++;
        }
        return head;
    }
};