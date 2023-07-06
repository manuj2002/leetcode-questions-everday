class Solution {
public:
  map<pair<int,int>,int>dp;
 int dfs(int i,int buy,vector<int>& prices)
 {
     if(dp.count({i,buy})>0)
          return(dp[{i,buy}]);
     if(i>=prices.size())
     {
         return(dp[{i,buy}]=0);
     }
     int ans=0;
     if(buy==1)
     {
         ans=max(ans,dfs(i+1,0,prices)-prices[i]);
         ans=max(ans,dfs(i+1,1,prices));
     }
     else
     {
         ans=max(ans,dfs(i+2,1,prices)+prices[i]);
         ans=max(ans,dfs(i+1,0,prices));
     }   
     return(dp[{i,buy}]=ans);
 }
    int maxProfit(vector<int>& prices) {
      return(dfs(0,1,prices));
    }
};