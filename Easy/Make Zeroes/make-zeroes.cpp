//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    void MakeZeros(vector<vector<int> >& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> temp = matrix;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(temp[i][j] == 0){
                    int sum = 0;
                    if(i > 0)
                        sum += temp[i-1][j], matrix[i-1][j] = 0;
                    if(j > 0)
                        sum += temp[i][j-1], matrix[i][j-1] = 0;
                    if(i < n-1)
                        sum += temp[i+1][j], matrix[i+1][j] = 0;
                    if(j < m-1)
                        sum += temp[i][j+1], matrix[i][j+1] = 0;
                    matrix[i][j] = sum;
                }
            }
        }
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		ob.MakeZeros(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cout << matrix[i][j] <<" ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends