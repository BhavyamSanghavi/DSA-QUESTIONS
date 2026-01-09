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
14    unordered_map<TreeNode*, int>depth;
15    int countDepth(TreeNode* root){
16        if(!root)
17            return 0;
18        if(!depth.count(root))
19            depth[root] = 1 + max(countDepth(root->left), countDepth(root->right));
20        return depth[root];
21    }
22    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
23        if(!root)
24            return NULL;
25        int l = countDepth(root->left);
26        int r = countDepth(root->right);
27        if(l == r)
28            return root;
29        else if(l < r)
30            return subtreeWithAllDeepest(root->right);
31        else
32            return subtreeWithAllDeepest(root->left);
33    }
34};