//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
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

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
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

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
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
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
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
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends