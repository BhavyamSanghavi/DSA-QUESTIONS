class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        double profit=0;
        
        priority_queue<pair<double,int>>pq;
        for(int i=0;i<val.size();i++)
            pq.push({(double)val[i]/wt[i], i});
        
        while(capacity>0 && !pq.empty())
        {
            auto element=pq.top(); pq.pop();
            int i=element.second;
            
            if(wt[i]<=capacity)
            {
                capacity-=wt[i];
                profit+=val[i];
            }
            else
            {
                // cout<<profit<<endl;
                double weight=(double)capacity/wt[i];
                // cout<<weight<<endl;
                profit+=weight*val[i];
                break;
            }
        }
        
        return profit;
    }
};
