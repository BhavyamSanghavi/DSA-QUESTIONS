/*
Definition for Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int count=0;
    void inorder(Node* root)
    {
        if(!root) return;
        inorder(root->left);
        count++;
        inorder(root->right);
    }
    int getSize(Node* root) {
        inorder(root);
        return count;
        
    }
};