class Solution {
  public:
    void listXOR(vector<int> &res, int x){
        for(int i=0;i<res.size();i++){
            res[i] = res[i] ^ x;
        }
    }
    vector<int> constructList(vector<vector<int>> &queries) {
        int q=queries.size();
        vector<int> res = {0};
        int cumulative_xor =0;
        for(int i=0;i<q;i++){
            if(queries[i][0] == 0){
                res.push_back(cumulative_xor^queries[i][1]);
            }
            else{
                cumulative_xor = cumulative_xor^queries[i][1];
            }
        }
        listXOR(res,cumulative_xor);
        sort(res.begin(),res.end());
        return res;
    }
};
