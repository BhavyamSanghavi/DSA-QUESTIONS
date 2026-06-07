/* Structure of a Linked List node
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
    Node* reverse(Node* head)
    {
        if(!head || !head->next) return head;
        Node* curr=head;
        Node* prev=NULL;
        Node* nxt=NULL;
        
        while(curr)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    Node *compute(Node *head) {
        if(!head || !head->next) return head;
        
        head=reverse(head);
        int val=head->data;
        Node* temp=head;

        while(temp->next)
        {
            if(temp->next->data<temp->data)
                temp->next=temp->next->next;
            else
                temp=temp->next;
        }
        head=reverse(head);
        return head;
    }
};