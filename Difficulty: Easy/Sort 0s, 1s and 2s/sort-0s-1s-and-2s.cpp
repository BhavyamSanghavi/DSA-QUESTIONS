//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sort012(vector<int>& arr) {
        int zero=0,one=0,two=arr.size()-1;
        while(one<=two)
        {
            if(arr[one]==1)
            {
                one++;
            }
            else if(arr[one]==0)
            {
                swap(arr[one],arr[zero]);
                one++;
                zero++;
            }
            else
            {
                swap(arr[one],arr[two]);
                // one++;
                two--;
            }
        }
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends