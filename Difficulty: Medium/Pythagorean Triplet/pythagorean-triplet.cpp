class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        if(arr.size()<3) return false;
        unordered_set<int>t;
        for(int i:arr) t.insert(i*i);
        
        for(int i=0;i<arr.size()-1;i++)
        {
            for(int j=i+1;j<arr.size();j++)
            {
                int sum=arr[i]*arr[i]+arr[j]*arr[j];
                if(t.find(sum)!=t.end()) return 1;
            }
        }
        return 0;
        
    }
};