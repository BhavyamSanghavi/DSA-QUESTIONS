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
13    ListNode* deleteMiddle(ListNode* head) {
14        if(!head || !head->next)return NULL;
15        ListNode*slow=head,*fast=head->next->next;
16        while(fast && fast->next)
17        {
18            fast=fast->next;
19            fast=fast->next;
20            slow=slow->next;
21        }
22        slow->next=slow->next->next;
23        // slow=slow->next;
24        // slow->next=NULL;
25        return head;
26    }
27};