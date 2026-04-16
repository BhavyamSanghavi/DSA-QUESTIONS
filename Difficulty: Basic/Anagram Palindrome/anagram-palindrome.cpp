class Solution {
  public:
    bool canFormPalindrome(string &s) {
        // code here
        unordered_map<char, int> freq;
        
        for (char ch : s) {
            freq[ch]++;
        }
    
        int oddCount = 0;
    
        for (auto it=freq.begin();it!=freq.end();it++) {
            if (it->second % 2 != 0) {
                oddCount ++;
            } 
            if(oddCount == 2){
                return 0;
            }
        }
    
        return 1;
    }
};