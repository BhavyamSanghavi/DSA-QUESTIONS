1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    ListNode* getmid(ListNode*head)
14    {
15        if(head==NULL) return NULL;
16        ListNode*slow=head, *fast=head;
17        while(fast && fast->next)
18        {
19            slow=slow->next;
20            fast=fast->next->next;
21        }
22        return slow;
23    }
24    ListNode* reverse(ListNode* head)
25    {
26        if(head==NULL) return NULL;
27        ListNode* prev=NULL, *curr=head, *nxt=NULL;
28        while(curr)
29        {
30            nxt=curr->next;
31            curr->next=prev;
32            prev=curr;
33            curr=nxt;
34        }
35        return prev;
36    }
37    int pairSum(ListNode* head) {
38        ListNode* mid=getmid(head);
39        mid=reverse(mid);
40        int ans=INT_MIN;
41        while(mid)
42        {
43            ans=max(ans,mid->val+head->val);
44            head=head->next;
45            mid=mid->next;
46        }
47        return ans;
48    }
49};