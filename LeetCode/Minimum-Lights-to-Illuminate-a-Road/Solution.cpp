class Solution {
public:
    int minLights(vector<int>& lights) {
        int n=lights.size();

        vector<int> diff(n+1);

        for(int i=0;i<n;i++){
            if(lights[i]){
                int l= max(0,i-lights[i]);
                int r= min(n-1,i+lights[i]);
                diff[l]++;
                diff[r+1]--;
            }
        }
        int pre=0;
        vector<bool> illuminated(n);
        for(int i=0;i<n;i++){
            pre+=diff[i];
            illuminated[i] = pre > 0;
        }
        int i=0;
        int ans=0;
        while(i<n){
            while(i<n and illuminated[i]) i++; // skip all iluminated positions
            int j=i;

            while(j<n and !illuminated[j]) j++; // all dark places
            // len if from [i,j-1]== (j-1) -i +1 = j-i==len
            ans += (j-i +2)/3; // ans += ceil(len/3)
            i=j;
        }
        return ans;
    }
};