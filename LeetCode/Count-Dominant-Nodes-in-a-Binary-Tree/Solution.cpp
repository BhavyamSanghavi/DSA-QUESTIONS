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
14    int ans=0;
15    int solve(TreeNode* root)
16    {
17        if(!root) return 0;
18        if(!root->left && !root->right) 
19        {
20            ans++;
21            return root->val;
22        }
23        
24
25        int left=solve(root->left);
26        int right=solve(root->right);
27
28        if(root->val>=left && root->val>=right) ans++;
29        return max({root->val,left,right});
30    }
31    int countDominantNodes(TreeNode* root) {
32        solve(root);
33        return ans;
34    }
35};