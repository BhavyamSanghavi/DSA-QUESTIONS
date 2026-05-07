/*
Definition for Node
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool check(Node* t, Node* s)
    {
        if(!t && !s) return true;
        if(!t&&s || !s && t || t->data!=s->data) return false;
        
        return check(t->left, s->left) && check(t->right,s->right);
    }
    bool getNodes(Node*t, Node* s)
    {
        if(!t) return false;
        if(t->data==s->data && check(t,s)) return 1;
        bool l=getNodes(t->left,s);
        bool r=getNodes(t->right,s);
        return l || r;
    }
    bool isSubTree(Node *root1, Node *root2) {
        // code here
        return getNodes(root1, root2);
    }
};

