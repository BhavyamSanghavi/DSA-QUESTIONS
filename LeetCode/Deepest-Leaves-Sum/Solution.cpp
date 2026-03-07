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
14    int deepestLeavesSum(TreeNode* root) {
15        queue<TreeNode*>q;
16        q.push(root);
17        int ans=0;
18
19        while(!q.empty())
20        {
21            int size=q.size();
22            int sum=0;
23            for(int i=0;i<size;i++)
24            {
25                TreeNode* node=q.front(); q.pop();
26                sum+=node->val;
27                if(node->left) q.push(node->left);
28                if(node->right) q.push(node->right);
29            }
30            ans=sum;
31        }
32        return ans;
33    }
34};