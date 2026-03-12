class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans(n);
        stack<int>s;
        
        for(int i=n-1;i>=0;i--)
        {
            int ele=arr[i];
            while(!s.empty() && s.top()>=ele) s.pop();
            
            if(s.empty()) ans[i]=-1;
            else ans[i]=s.top();
            
            s.push(ele);
        }
        return ans;
    }
};