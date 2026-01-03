/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    Node* mergeSortedList(Node* root1, Node* root2)
    {
        if(!root1) return root2;
        if(!root2) return root1;
        
        Node* ansHead=new Node(-1);
        Node* curr=ansHead;
        while(root1 && root2)
        {
            if(root1->data<root2->data)
            {
                curr->bottom=new Node(root1->data);
                curr=curr->bottom;
                root1=root1->bottom;
            }
            else
            {
                curr->bottom=new Node(root2->data);
                curr=curr->bottom;
                root2=root2->bottom;
            }
        }
        while(root1)
        {
            curr->bottom=new Node(root1->data);
            curr=curr->bottom;
            root1=root1->bottom;
        }
        while(root2)
        {
            curr->bottom=new Node(root2->data);
            curr=curr->bottom;
            root2=root2->bottom;
        }
        return ansHead->bottom;
    }
    Node *flatten(Node *root) {
        Node* head=root;
        Node* temp=root->next;
        while(temp)
        {
            head=mergeSortedList(head,temp);
            temp=temp->next;
        }
        return head;
    }
};