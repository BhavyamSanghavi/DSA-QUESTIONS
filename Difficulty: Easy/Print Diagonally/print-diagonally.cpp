class Solution {
  public:
    
    vector<int> diagView(vector<vector<int>> mat) {
        // code here
        vector<int>ans;
        int n=mat.size();
        for(int x=0;x<2*n-1;x++)
        {
            int i=(x<n) ? 0:x-n+1;
            int j=(x<n) ? x:n-1;
            while(i<mat.size() && j>=0)
                ans.push_back(mat[i++][j--]);    
        }
        return ans;
    }
};