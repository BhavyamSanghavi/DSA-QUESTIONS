//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->bottom;
    }
    printf("\n");
}

Node* createLinkedList(vector<Node*>& v) {
    Node* head = new Node(0);
    Node* temp = head;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        temp->next = v[i];
        temp = temp->next;
    }
    return head->next;
}


// } Driver Code Ends

/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node* merge(Node* r1, Node*r2)
    {
        if(!r1) return r2;
        if(!r2) return r1;
        
        Node* ansHead=new Node(-1);
        Node* ans=ansHead;
        
        while(r1 && r2)
        {
            if(r1->data<r2->data)
            {
                ans->bottom=r1;
                r1=r1->bottom;
            }
            else
            {
                ans->bottom=r2;
                r2=r2->bottom;
            }
            
            ans=ans->bottom;
        }
        if(r1) ans->bottom=r1;
        if(r2) ans->bottom=r2;
        
        return ansHead->bottom;
    }
    Node *flatten(Node *root) {
        while(root->next)
        {
            Node* nextnode=root->next;
            root=merge(root,nextnode);
            root->next=nextnode->next;
            nextnode->next=NULL;
            
        }
        return root;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node*> v(n);

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            Node* head = new Node(0);
            Node* temp = head;
            int x;
            while (ss >> x) {
                Node* newNode = new Node(x);
                temp->bottom = newNode;
                temp = temp->bottom;
            }
            v[i] = head->bottom;
        }

        Solution ob;
        Node* list = createLinkedList(v);
        Node* head = ob.flatten(list);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends