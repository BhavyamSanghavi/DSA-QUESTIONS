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
    vector<vector<int>> verticalOrder(Node *root) {
        map<int,vector<int>>m;
        queue<pair<Node*, int>>q;
        q.push({root,0});
        
        while(!q.empty())
        {
            auto t=q.front(); q.pop();
            Node* node=t.first;
            int ht=t.second;
            
            m[ht].push_back(node->data);
            if(node->left) q.push({node->left,ht-1});
            if(node->right) q.push({node->right,ht+1});
        }
        
        vector<vector<int>>ans;
        for(auto i:m)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};