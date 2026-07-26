class Solution {
  public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        int n=arr.size();
        int ind=0,x=0;
        vector<vector<int>>ans;
        
        while(1)
        {
            vector<int>t;
            int size=(1<<x);
            x++;
            
            for(int i=0;i<size;i++)
            {
                if(ind>=n) break;
                t.push_back(arr[ind++]);
            }
            sort(t.begin(),t.end());
            ans.push_back(t);
            if(ind>=n) break;
        }
        
        return ans;
    }
};
