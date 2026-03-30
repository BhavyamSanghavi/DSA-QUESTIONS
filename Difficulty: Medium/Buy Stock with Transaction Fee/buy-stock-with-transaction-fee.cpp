class Solution {
  public:
    int solve(vector<int>& arr, int k, int i, bool buy)
    {
        if(i>=arr.size()) return 0;
        int profit=0;
        
        if(buy)
        {
            int buystock=-arr[i]+solve(arr,k,i+1,!buy);
            int skip=solve(arr,k,i+1,buy);
            profit+=max(skip,buystock);
        }
        else
        {
            int sell=arr[i]-k+solve(arr,k,i+1,!buy);
            int skip=solve(arr,k,i+1,buy);
            profit+=max(sell,skip);
        }
        return profit;
    }
    int maxProfit(vector<int>& arr, int k) {
        
        int profit=0,buy=INT_MIN;
        for(int i=0;i<arr.size();i++)
        {
            int price=arr[i];
            buy=max(buy,profit-price-k);
            profit=max(profit,buy+price);
        }
        return profit ;
        
    }
};