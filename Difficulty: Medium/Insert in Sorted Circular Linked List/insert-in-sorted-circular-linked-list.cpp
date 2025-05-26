/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
        Node* newnode=new Node(data);
        if(head->data>data)
        {
            newnode->next=head;
            Node* t=head;
            while(t->next!=head) t=t->next;
            t->next=newnode;
            return newnode;
        }
        Node* curr=head->next;
        Node* prev=head;
        while(curr->data<data && curr!=head)
        {
            prev=curr;
            curr=curr->next;
        }
        prev->next=newnode;
        newnode->next=curr;
        return head;
    }
};