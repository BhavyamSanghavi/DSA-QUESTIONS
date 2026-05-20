class Solution {
  public:
    bool isProduct(vector<int>& arr, long long target) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        for(int i=0;i<arr.size();i++){
            if(!arr[i]&&!target) return 1;
            else if(arr[i]&&target%arr[i]==0){
                int num = target/arr[i];
                if(num==arr[i]){
                    if(mp[num]>=2)return 1;
                } else if(mp[num]){
                    return 1;
                }
            }
        }
        return 0;
    }
};