class Solution {
  public:
    int getNextPerson(vector<char>& arr, int i, char person)
    {
        while(i<arr.size() && arr[i]!=person) i++;
        if(i==arr.size()) return -1;
        return i;
    }
    int catchThieves(vector<char> &arr, int k) {
        int totalThieves=0;
        int currPolice=getNextPerson(arr,0,'P');
        int currThief=getNextPerson(arr,0,'T');
        while(currPolice!=-1 && currThief!=-1)
        {
            if(abs(currPolice-currThief)<=k)
            {
                totalThieves++;
                currPolice=getNextPerson(arr,currPolice+1,'P');
                currThief=getNextPerson(arr,currThief+1,'T');
            }
            else if(currPolice<currThief)
                currPolice=getNextPerson(arr,currPolice+1,'P');
            else
                currThief=getNextPerson(arr,currThief+1,'T');
        }
        return totalThieves;
    }
};