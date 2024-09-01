//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxPathSum(vector<int> &A, vector<int> &B) {
        int l1=A.size(), l2=B.size();
        
        int sum1=0,sum2=0,maxsum=0;
        int i=0,j=0;
        while(i < l1 && j < l2)
        {
            if(A[i] < B[j])
            {
                sum1+=A[i];
                i++;
            }
            
            else if(B[j] < A[i])
            {
                sum2+=B[j];
                j++;
            }
            
            else
            {
                maxsum+=max(sum1,sum2)+A[i];
                sum1=0,sum2=0;
                i++;j++;
            }
        }
        
        while(i < l1)
         sum1+=A[i++];
        
        while(j < l2)
         sum2+=B[j++];
        
        return maxsum + max(sum1,sum2); 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }
        vector<int> arr2;
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            arr2.push_back(number2);
        }
        Solution ob;
        long long ans = ob.maxPathSum(arr1, arr2);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends