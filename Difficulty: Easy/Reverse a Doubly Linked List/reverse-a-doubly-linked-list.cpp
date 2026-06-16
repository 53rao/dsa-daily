/* Structure of doubly linked list node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        Node* first=head->next;
        Node* curr=head->next;
        Node* prev=head;
        
        while(curr){
            Node* temp=curr->next;
            curr->next=prev;
            curr->prev=temp;
            prev=curr;
            curr=temp;
        }
        head->prev=first;
        head->next=nullptr;
        return prev;
    }
};