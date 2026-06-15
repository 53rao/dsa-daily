/*
class Node {
  public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
*/
class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        // Code here
        Node* curr =head;
            Node* temp=(Node*)malloc(sizeof(Node()));
            temp->data=x;
            if(head==NULL)
                return temp;
            while(curr->next)
                curr=curr->next;
            curr->next=temp;
            return head;
    }
};