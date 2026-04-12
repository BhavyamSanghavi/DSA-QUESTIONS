1class Solution {
2public:
3    bool isPrime(int n) 
4    {
5        if (n <= 1) return false;
6        if (n <= 3) return true; 
7        if (n % 2 == 0 || n % 3 == 0) return false;
8
9        for (int i = 5; i * i <= n; i += 6) 
10        {
11            if (n % i == 0 || n % (i + 2) == 0)
12                return false;
13        }
14        return true;
15    }
16    int minOperations(vector<int>& nums) {
17        int ans=0;
18        for(int i=0;i<nums.size();i++)
19        {
20            if(i%2==0)
21            {
22                while(!isPrime(nums[i]))
23                {
24                    nums[i]++;
25                    ans++;
26                }
27            }
28            else
29            {
30                while(isPrime(nums[i]))
31                {
32                    nums[i]++;
33                    ans++;
34                }
35            }
36        }
37        return ans;
38    }
39};