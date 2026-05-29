class Solution {
  public:
    void replaceElements(vector<int>& arr) {
        vector<int>t(arr.size());
        for(int i=1;i<arr.size()-1;i++)
            t[i]=arr[i-1]^arr[i+1];
        t[0]=arr[0]^arr[1];
        t[t.size()-1]=arr[arr.size()-1]^arr[arr.size()-2];
        arr=t;
    }
};