class Solution {
  public:
    vector<int> leafNodes(vector<int>& preorder) {
        // code here
        stack<int> s;
        int n = preorder.size();
        vector<int> ans;
        
        // first pop will be the answer
        s.push(preorder[0]);
        for (int i = 1; i < n; i++){
            int count = 0;
            int top = s.top();
            while (!s.empty() && preorder[i] > s.top()){
                s.pop();
                count++;
            }
            if (count >= 2){
                ans.push_back(top);
            }
            s.push(preorder[i]);
        }
        
        if (ans.empty() || ans.back() != preorder[n - 1]){
            ans.push_back(preorder[n - 1]);
        }
        return ans;
    }
};