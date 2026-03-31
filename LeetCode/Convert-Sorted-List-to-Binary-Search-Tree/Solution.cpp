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
11/**
12 * Definition for a binary tree node.
13 * struct TreeNode {
14 *     int val;
15 *     TreeNode *left;
16 *     TreeNode *right;
17 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
18 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
19 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
20 * };
21 */
22class Solution {
23public:
24    TreeNode* buildBST(vector<int>& nums, int start, int end)
25    {
26        if(start>end) return NULL;
27        
28        int mid=(start+end)/2;
29        TreeNode* root=new TreeNode(nums[mid]);
30
31        root->left=buildBST(nums,start,mid-1);
32        root->right=buildBST(nums,mid+1,end);
33
34        return root;
35    }
36
37    TreeNode* sortedListToBST(ListNode* head) {
38        vector<int>nums;
39        while(head)
40        {
41            nums.push_back(head->val);
42            head=head->next;
43        }
44
45        return buildBST(nums,0,nums.size()-1);
46    }
47};