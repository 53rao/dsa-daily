## [Insertion to a linked list](https://www.geeksforgeeks.org/problems/linked-list-insertion-1587115620/1)
```
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
```
## [Delete a node](https://leetcode.com/problems/delete-node-in-a-linked-list/)
```
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
    void deleteNode(ListNode* node) {
        ListNode* curr=node;
        ListNode* prev=NULL;
        while(curr->next){
            curr->val=(curr->next)->val;
            prev=curr;
            curr=curr->next;
        }
        prev->next=NULL;
    }
};
```
##