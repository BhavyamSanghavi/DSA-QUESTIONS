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
14    int getSum(TreeNode* root)
15    {
16        if(!root) return 0;
17        return root->val+getSum(root->left)+getSum(root->right);
18    }
19    long long ans=0;
20    int getMaxProduct(TreeNode* root, int& total)
21    {
22        if(!root) return 0;
23        int leftProduct=getMaxProduct(root->left,total);
24        int rightProduct=getMaxProduct(root->right,total);
25        int sum=leftProduct+rightProduct+root->val;
26        ans = max(ans, (1LL * (total - sum) * sum));
27        return sum;
28    }
29    int maxProduct(TreeNode* root) {
30        if(!root)    return 0;
31        int total=getSum(root);
32        int sum=getMaxProduct(root,total);
33        return ans%1000000007;
34    }
35};