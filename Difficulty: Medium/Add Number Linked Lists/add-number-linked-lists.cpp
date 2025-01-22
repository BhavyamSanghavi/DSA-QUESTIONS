//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
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
        Node* curr=head, * prev=NULL, *nxt=NULL;
        while(curr)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    Node* addTwoLists(Node* num1, Node* num2)
    {
        num1=reverse(num1);
        num2=reverse(num2);
        Node* ans=new Node(-1);
        Node*t=ans;
        int carry=0;
        
        while(num1 && num2)
        {
            int sum=num1->data+num2->data+carry;
            Node* newnode=new Node(sum%10);
            carry=sum/10;
            
            t->next=newnode;
            t=t->next;
            num1=num1->next;
            num2=num2->next;
        }
        while(num1)
        {
            int sum=num1->data+carry;
            Node* newnode=new Node(sum%10);
            carry=sum/10;
            
            t->next=newnode;
            t=t->next;
            num1=num1->next;
        }
        while(num2)
        {
            int sum=num2->data+carry;
            Node* newnode=new Node(sum%10);
            carry=sum/10;
            
            t->next=newnode;
            t=t->next;
            num2=num2->next;
        }
        
        if(carry)
        {
            Node*newnode=new Node(carry);
            t->next=newnode;
        }
        ans=reverse(ans->next);
        while(ans && ans->data==0) ans=ans->next;
        if(!ans) return new Node(0);
        return ans;
    }
    // Node* addTwoLists(Node* num1, Node* num2) {
    //     // code here
    // }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends