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
14
15    int maxDepth(TreeNode* root) {
16        if(root==NULL)      return 0;
17        return 1+max(maxDepth(root->left),maxDepth(root->right));
18    }
19    bool isBalanced(TreeNode* root) {
20      if(!root)return true;
21      int l=maxDepth(root->left)  ;
22      int r=maxDepth(root->right);
23      bool ansleft=isBalanced(root->left);
24      bool ansright=isBalanced(root->right);
25      bool cond= abs(l-r)<=1;
26      return ansleft && ansright && cond;
27    }
28};