//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
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
class Solution{
     struct Node* Reverse(struct Node* &head)
    {
        Node *curr = head;
        Node *forw;
        Node *prev = NULL;
        while(curr!=NULL)
        {
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }
    public:
    struct Node* modifyTheList(struct Node *head)
    {
        Node* fast = head;
        Node* slow = head;
        Node* prev = head;
        while(fast!=NULL && fast->next!=NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        Node* l1 = head;
        Node* l2 = Reverse(slow);
        slow = l2;
        while(l1!=NULL && l2!=NULL){
            int d1 = l1->data;
            int d2 = l2->data;
            l2->data = d1;
            l1->data = d2-d1;
            l1 = l1->next;
            l2 = l2->next;
        }
        Node* curr = Reverse(slow);
        Node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = curr;
        return head;
        
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends