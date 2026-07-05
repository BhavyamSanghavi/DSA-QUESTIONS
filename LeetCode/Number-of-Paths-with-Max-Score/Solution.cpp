class Solution {
public:
    int n,m;
    const int mod=1e9+7;
 //   vector<string>board;
  //  vector<vector<pair<int,int>>>dp;
  //  pair<int,int>f(int i,int j){
    //   if(i==0 && j==0) return {0,1};
     //  if(i<0 || j<0) return {-1,0};
     //  if(board[i][j]=='X') return {-1,0};
     //  if(dp[i][j]!=pair<int,int>(-1,-1)) return dp[i][j];
     //  pair<int,int>up=f(i-1,j);
       //pair<int,int>left=f(i,j-1);
     //  pair<int,int>diagnol=f(i-1,j-1);
     //  int maxi=max({up.first,left.first,diagnol.first});
      // if(maxi==-1) return dp[i][j]={-1,0};
      // int cnt=0;
      // if(up.first==maxi) cnt=(cnt+up.second)%mod;
      // if(left.first==maxi) cnt=(cnt+left.second)%mod;
      // if(diagnol.first==maxi)  cnt=(cnt+diagnol.second)%mod;
      // int val=(board[i][j]=='S')?0:board[i][j]-'0';
      // return dp[i][j]={val+maxi,cnt%mod};
    //}
    vector<int> pathsWithMaxScore(vector<string>& board) {
        this->n=board.size();
        this->m=board[0].size();
      //  this->board=board;
     //   dp.assign(n,vector<pair<int,int>>(m,{-1,-1}));
       // auto it=f(n-1,m-1);
       // if(it.first==-1) return {0,0};
       // return {(int)it.first,(int)it.second};


       
       //vector<vector<pair<int,int>>>dp(n,vector<pair<int,int>>(m,{-1,-1}));
       //dp[0][0]=pair<int,int>(0,1);
       //for(int i=0;i<n;i++){
        //for(int j=0;j<m;j++){
          //  if(i==0 && j==0) continue;
            //if(board[i][j]=='X'){
              //  dp[i][j]=pair<int,int>(-1,0);
                //continue;
           // }
           // pair<int,int>up=pair<int,int>(-1,0);
           // pair<int,int>left=pair<int,int>(-1,0);
         //   pair<int,int>diagnol=pair<int,int>(-1,0);
           // if(i-1>=0) up=dp[i-1][j];
          //  if(j-1>=0) left=dp[i][j-1];
          //  if(i-1>=0 && j-1>=0) diagnol=dp[i-1][j-1];
          //  int maxi=max({up.first,left.first,diagnol.first});
          //  if(maxi==-1){
            //    dp[i][j]={-1,0};
              //  continue;
           // }
           // int cnt=0;
            //if(up.first==maxi) cnt=(cnt+up.second)%mod;
            //if(left.first==maxi) cnt=(cnt+left.second)%mod;
            //if(diagnol.first==maxi)  cnt=(cnt+diagnol.second)%mod;
            //int val=(board[i][j]=='S')?0:board[i][j]-'0';
            //dp[i][j]=pair<int,int>(val+maxi,cnt%mod);
      //  }
       //}
      // auto it=dp[n-1][m-1];
      // if(it.first==-1) return {0,0};
      // return {it.first,it.second};

      vector<pair<int,int>>curr(m,{-1,-1});
      vector<pair<int,int>>prev(m,{-1,-1});
      prev[0]=pair<int,int>(0,1);
      curr[0]=pair<int,int>(0,1);
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          if(i==0 && j==0) continue;
          if(board[i][j]=='X'){
            curr[j]=pair<int,int>(-1,0);
            continue;
          }
          pair<int,int>left=pair<int,int>(-1,0);
          pair<int,int>up=pair<int,int>(-1,0);
          pair<int,int>diagnol=pair<int,int>(-1,0);
          if(i-1>=0) up=prev[j];
          if(j-1>=0) left=curr[j-1];
          if(i-1>=0 && j-1>=0) diagnol=prev[j-1];
          int maxi=max({up.first,left.first,diagnol.first});
          if(maxi==-1){
            curr[j]=pair<int,int>(-1,0);
            continue;
          }
          int cnt=0;
          if(up.first==maxi) cnt=(cnt+up.second)%mod;
          if(left.first==maxi) cnt=(cnt+left.second)%mod;
          if(diagnol.first==maxi) cnt=(cnt+diagnol.second)%mod;
          int val=(board[i][j]=='S')?0:board[i][j]-'0';
          curr[j]=pair<int,int>(val+maxi,cnt);
       }
       prev=curr;
      }
      auto it=prev[m-1];
      if(it.first==-1) return {0,0};
      return {it.first,it.second};
    }
};