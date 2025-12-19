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
14    void solve(TreeNode* root, int targetSum, vector<int>& curr ,vector<vector<int>>& ans)
15    {
16        if(!root) return;
17        if(!root->left && !root->right)
18        {
19            targetSum-=root->val;
20            if(targetSum==0) 
21            {
22                curr.push_back(root->val);
23                ans.push_back(curr);
24                curr.pop_back();
25            }
26            return;
27        }
28        curr.push_back(root->val);
29        solve(root->left,targetSum-root->val,curr,ans);
30        solve(root->right,targetSum-=root->val,curr,ans);
31        curr.pop_back();
32    }
33    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
34        vector<vector<int>>ans;
35        vector<int>curr;
36        solve(root,targetSum,curr,ans);
37        return ans;
38    }
39};