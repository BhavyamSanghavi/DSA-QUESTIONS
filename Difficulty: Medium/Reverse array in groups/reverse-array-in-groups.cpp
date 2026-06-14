class Solution {
  public:
    void reverse(vector<int>& arr, int l, int r)
    {
        while(l<r)
            swap(arr[l++],arr[r--]);
    }
    void reverseInGroups(vector<int> &arr, int k) {
        int l=0,r=k-1;
        while(l<arr.size())
        {
            if(r>=arr.size()) r=arr.size()-1;
            reverse(arr,l,r);
            l=r+1;
            r=l+k-1;
        }
    }
};
