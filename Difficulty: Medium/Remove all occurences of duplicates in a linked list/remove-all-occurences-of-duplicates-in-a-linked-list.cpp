//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
// User function Template for C++

/* Linked List node structure

struct Node {
    int data;
    struct Node *next;
};

*/

class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        if(head==NULL||head->next==NULL) return head;
        struct Node*prev=NULL;
        struct Node* curr=head;
        while(curr!=NULL and curr->next!=NULL)
        {
            Node*temp=curr->next;
            if(curr->data!=temp->data)
            {
                prev=curr;
                curr=curr->next;
            }
            else
            {
                int d=curr->data;
                if(curr==head)
                {
                    while(head!=NULL && head->data==d)
                    {
                        head=head->next;
                    }
                    curr=head;
                }
                else
                {
                    while(curr!=NULL && curr->data==d)
                    {
                        curr=curr->next;
                    }
                    prev->next=curr;
                    
                }
            }
        }
        return head;
    }
};

//{ Driver Code Starts.
/* Function to print linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;

        cin >> N;

        Node *head = NULL;
        Node *temp = head;

        for (int i = 0; i < N; i++) {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Solution ob;
        head = ob.removeAllDuplicates(head);
        printList(head);

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends