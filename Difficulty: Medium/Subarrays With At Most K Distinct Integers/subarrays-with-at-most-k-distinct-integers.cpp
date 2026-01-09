class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        unordered_map<int,int>m;
        int i=0,j=0,ans=0;
        while(i<arr.size())
        {
            m[arr[i]]++;
            while(m.size()>k)
            {
                m[arr[j]]--;
                if(m[arr[j]]==0) m.erase(arr[j]);
                j++;
            }
            ans+=i-j+1;
            i++;
        }
        return ans;
    }
};