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
14    vector<vector<int>> levelOrderBottom(TreeNode* root) {
15        if(!root) return {};
16        vector<vector<int>>ans;
17        queue<TreeNode*>q;
18        q.push(root);
19
20        while(!q.empty())
21        {
22            int size=q.size();
23            vector<int>level;
24            for(int i=0;i<size;i++)
25            {
26                TreeNode* node=q.front(); q.pop();
27                level.push_back(node->val);
28
29                if(node->left) q.push(node->left);
30                if(node->right) q.push(node->right);
31            }
32            ans.push_back(level);
33        }
34        reverse(ans.begin(),ans.end());
35        return ans;
36    }
37};