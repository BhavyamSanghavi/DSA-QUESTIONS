class Solution {
  public:
    int minValue(string &s, int k) {
        // code here
        unordered_map<char,int>m;
        for(int i=0;i<s.size();i++) m[s[i]]++;
        priority_queue<int>pq;
        for(auto i:m) pq.push(i.second);
        
        while(k--)
        {
            int val=pq.top(); pq.pop();
            val--;
            pq.push(val);
        }
        
        int ans=0;
        while(!pq.empty())
        {
            int i=pq.top(); pq.pop();
            ans+=i*i;
        }
        return ans;
    }
};