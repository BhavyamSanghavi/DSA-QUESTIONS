class Solution {
  public:
    bool isPowerOfTwo(int n) 
    {
        return n > 0 && (n & (n - 1)) == 0;
    }
    
    string lexicographicallySmallest(string &s, int k) {
        if (k <= 0) return s;
        if(isPowerOfTwo(s.size())) k/=2;
        else k*=2;
        
        if(s.size()<=k) return "-1";
        stack<char>st;
        
        for (char c : s) {
            // Pop while we can make string smaller
            while (!st.empty() && k > 0 && st.top() > c) {
                st.pop();
                k--;
            }
            st.push(c);
        }
    
        // If still removals left, remove from end
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

