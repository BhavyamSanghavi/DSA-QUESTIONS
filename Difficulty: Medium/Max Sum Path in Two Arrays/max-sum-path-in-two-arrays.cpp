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