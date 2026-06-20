/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        int flag=0;
        Node* one=head;
        Node* middle;
        if(!head->next)
            return 0;
        Node* two=one->next;
        one=one->next;
        two=two->next;
        while(one&&two){
            if(one==two){
                flag=1;
                one=head;
                break;
            }
            one=one->next;
            two=two->next;
            if(two)
                two=two->next;
        }
        if(flag){
            int count=0;
            while(one&&two){
                
                if(one==two){
                    middle=one;
                    break;
                }
                one=one->next;
                two=two->next;
            }
            Node* curr=middle->next;
            count++;
            while(curr!=middle){
                curr=curr->next;
                count++;
            }
            return count;
        }
        return 0;
    }
};