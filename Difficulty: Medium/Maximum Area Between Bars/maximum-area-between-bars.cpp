class Solution {
  public:
    int maxArea(vector<int> &height) {
        int n=height.size();
        int l=0,r=n-1;
        int area=0;
        
        while(l<r)
        {
            if(height[l]<height[r])
                area=max(area,(r-l-1)*height[l++]);
            else
                area=max(area,(r-l-1)*height[r--]);
        }
        
        return area;
    }
};