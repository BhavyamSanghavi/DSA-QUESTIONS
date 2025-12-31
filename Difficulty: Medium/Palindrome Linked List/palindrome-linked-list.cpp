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
    Node* reverse(Node* head)
    {
        if(!head) return NULL;
        Node* curr=head;
        Node* prev=NULL;
        while(curr)
        {
            Node* nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    bool isPalindrome(Node *head) {
        Node* fast=head;
        Node* slow=head;
        
        while(fast && fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        slow=reverse(slow);
        while(slow)
        {
            if(head->data!=slow->data)
                return false;
            slow=slow->next;
            head=head->next;
        }
        return true;
        
        
    }
};