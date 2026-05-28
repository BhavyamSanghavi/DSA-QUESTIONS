/*
Definition for Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    int mini=1e9;
    Node* ans=NULL;
    void solve(Node* root, int k)
    {
        if(!root) return;
        if(mini>k-root->data && k-root->data>=0)
        {
            mini=k-root->data;
            ans=root;
        }
        if(root->data<k) solve(root->right,k);
        else solve(root->left,k);
    }
    int findMaxFork(Node* root, int k) {
        solve(root,k);
        if(!ans) return -1;
        return ans->data;
        
    }
};