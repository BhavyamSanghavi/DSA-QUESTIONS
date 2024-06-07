//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    void solve(int a[], int n, vector<string>&mapping, vector<string>& result, string s, int idx) {
        if(idx==n) {
            result.push_back(s);
            return;
        }
        int digit = a[idx];
        string map = mapping[digit];
        for(auto i:map) {
            s.push_back(i);
            solve(a,n,mapping,result,s,idx+1);
            s.pop_back();
        }
    }
    vector<string> possibleWords(int a[], int N)
    {
        vector<string>mapping = {"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>result;
        solve(a,N,mapping,result,"",0);
        return result;
    }


};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends