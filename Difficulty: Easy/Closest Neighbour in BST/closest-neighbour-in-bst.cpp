/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
  void solve(Node* root, int n, int & ans)
  {
      if(!root) return ;
      if(root->data<=n && root->data>ans) ans=root->data;
      if(root->data<n) solve(root->right,n,ans);
      else solve(root->left,n,ans);
  }
    int findMaxFork(Node* root, int n) {
        int ans=-1;
        solve(root,n,ans);
        return ans;
        
    }
    
};