class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        // code here
        vector<int> res;
        for(int i : arr){ 
            int ind = abs(i)-1;
            if(arr[ind] < 0){
                res.push_back(abs(i));
            }else{
                arr[ind] *= -1;
            }
        }
        return res;
    }
};