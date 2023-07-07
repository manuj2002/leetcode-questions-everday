class Solution {
public:

int dfs(int i,int j,vector<int>& nums,vector<vector<int>>&dp)
{
  if(dp[i][j]!=-1)
     return(dp[i][j]);
    if(j<i)
      return(dp[i][j]=0);
      int ans=0;
      for(int k=i;k<=j;k++)
      {
         int x=nums[k];
         if(i-1>=0)
          x*=nums[i-1];
          if(j+1<nums.size())
          x*=nums[j+1];
          if(i<=k-1)
          {
            x+=dfs(i,k-1,nums,dp);
          }
          if(k+1<=j)
          {
            x+=dfs(k+1,j,nums,dp);
          }
          ans=max(ans,x);
      }
      return(dp[i][j]=ans);
}


    int maxCoins(vector<int>& nums) {
  int n=nums.size();
  vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
       return(dfs(0,nums.size()-1,nums,dp));
    }
};