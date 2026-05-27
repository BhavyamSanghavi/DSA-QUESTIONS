/* Structure of binary tree node
class Node{
public:
    int data;
    Node* left, right;
    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
}
*/
class Solution {
  public:
    map<int,int>m;
  void solve(Node* root, int level)
  {
      if(root)
      {
          m[level]+=root->data;
          solve(root->left,level-1);
          solve(root->right,level+1);
      }
  }
    vector <int> verticalSum(Node *root) {
        solve(root,0);
        vector<int>ans;
        for(auto i:m) ans.push_back(i.second);
        return ans;
    }
};