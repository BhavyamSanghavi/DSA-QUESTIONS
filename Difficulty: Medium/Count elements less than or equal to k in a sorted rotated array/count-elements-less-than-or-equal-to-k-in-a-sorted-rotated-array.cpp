class Solution {
    public:
    int countLessEqual(vector<int>& arr, int x) {
        // code here
        int ans=0;
        for(int& i:arr)
            if(i<=x) ans++;
        return ans;
    }
};