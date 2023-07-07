class Solution {
public:



    int maxCoins(vector<int>& nums) {
  int n=nums.size();
  vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                int ans=0;
                for(int k=i;k<=j;k++)
                {
                   int x=nums[k] ;
                    if(i-1>=0)
                        x*=nums[i-1];
                    if(j+1<n)
                        x*=nums[j+1];
                    if(i<=k-1)
                        x+=dp[i][k-1];
                    if(k+1<=j)
                        x+=dp[k+1][j];
                    ans=max(ans,x);
                }
                dp[i][j]=ans;
            }
        }
        return(dp[0][n-1]);
      
    }
};