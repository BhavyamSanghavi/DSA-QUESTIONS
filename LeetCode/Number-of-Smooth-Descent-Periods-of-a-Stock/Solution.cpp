class Solution {
    public long getDescentPeriods(int[] prices) {
        long res = 1;
        
        for(int i = 0, j = 1; j < prices.length; j++) {
            if(prices[j] != prices[j - 1] - 1)//streak broken move i to j
                i = j;
            
            res += j - i + 1;//j - i + 1 = number of subarrays
        }
        return res;
    }
}