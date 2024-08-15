//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
     Node* reverse(Node* &head){
        Node* pre = NULL;
        Node* curr = head;
        Node* forward = NULL;
        while(curr != NULL){
            forward = curr->next;
            curr->next = pre;
            pre = curr;
            curr = forward;
        }
        return pre;
    }
    Node* addOne(Node *head) 
    {
        head=reverse(head);
         Node *temp = head;
       while(temp != NULL) {
           if(temp -> next == NULL && temp -> data == 9) {
               temp -> data = 1;
               Node *newnode = new Node(0);
               newnode -> next = head;
               head = newnode;
               temp = temp -> next;
           }
           else if(temp -> data == 9) {
               temp -> data = 0;
               temp = temp -> next;
           }
           else {
               temp -> data = temp -> data + 1;
               break;
           }
       }
       head = reverse(head);
       return head;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends