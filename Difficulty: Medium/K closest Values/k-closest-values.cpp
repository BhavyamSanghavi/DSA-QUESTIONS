/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void inorder(priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>& pq, Node* root, int target)
    {
        if(!root) return;
        inorder(pq,root->left,target);
        pq.push({abs(target-root->data),root->data});
        inorder(pq,root->right,target);
    }
    vector<int> getKClosest(Node* root, int target, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
        inorder(pq,root,target);
        vector<int>ans;
        while(!pq.empty() && k--)
        {
            int res=pq.top().second; pq.pop();
            ans.push_back(res);
        }
        return ans;
    }
};