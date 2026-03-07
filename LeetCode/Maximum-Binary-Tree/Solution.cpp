1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    TreeNode* solve(vector<int>& nums, int start, int end)
15    {
16        if(start>end) return NULL;
17        int maxi=-1,ind=-1;
18        for(int i=start;i<=end;i++) 
19        {
20            if(maxi<nums[i])
21            {
22                maxi=nums[i];
23                ind=i;
24            }
25        }
26        TreeNode* root=new TreeNode(maxi);
27
28        root->left=solve(nums,start,ind-1);
29        root->right=solve(nums,ind+1,end);
30
31        return root;
32    }
33    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
34        return solve(nums,0,nums.size()-1);
35    }
36};