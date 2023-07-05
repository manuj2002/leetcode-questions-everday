class Solution {
public:
     int dfs(int i,int buy,int cap,vector<int>& prices, vector<vector<vector<int>>>&dp)
    {
        if(dp[i][buy][cap]!=-1)
            return(dp[i][buy][cap]);
        if(i==prices.size()||cap==0)
             return(dp[i][buy][cap]=0);
        
        int ans=0;
         if(buy==1)
         {
             ans=max(ans,dfs(i+1,0,cap,prices,dp)-prices[i]);
              ans=ans=max(ans,dfs(i+1,1,cap,prices,dp));
         }
        else
        {
            ans=max(ans,dfs(i+1,1,cap-1,prices,dp)+prices[i]);
              ans=ans=max(ans,dfs(i+1,0,cap,prices,dp));
        } 
        return(dp[i][buy][cap]=ans);
    }

    int maxProfit(int k, vector<int>& prices) {
      int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2+1,vector<int>(k+1,-1)));
        return(dfs(0,1,k,prices,dp));
    }
};