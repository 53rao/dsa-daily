/*
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};
*/

class Solution {
  public:
    Node *insertAtPos(Node *head, int p, int x) {
        // code here
        Node* curr=head;
        Node* temp=(Node*)malloc(sizeof(Node(0)));
        temp->data=x;
        Node* prev=nullptr;
        int k=0;
        
        while(curr&&k<=p){
            prev=curr;
            curr=curr->next;
            k++;
            
        }
        if(curr){
            temp->next=prev->next;
            curr->prev=temp;
            prev->next=temp;
            temp->prev=prev;
        }
        else{
            prev->next=temp;
            temp->prev=prev;
        }
            
        
        return head;
        
    }
};