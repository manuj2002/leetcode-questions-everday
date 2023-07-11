class Solution {
public:
    int dfs(int i,vector<int>& arr,int d,vector<int>&dp)
    {
        if(dp[i]!=-1)
            return(dp[i]);
        int k=arr[i];
        int n=arr.size();
        int j=i-1;
        int ans=0;
        while(j>=0 && i-j<=d && arr[j]<k)
        {
            ans=max(ans,1+dfs(j,arr,d,dp));
            j--;
        }
        j=i+1;
         while(j<n && j-i<=d && arr[j]<k)
        {
            ans=max(ans,1+dfs(j,arr,d,dp));
             j++;
        }
        return(dp[i]=ans);
        
    }
    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();
        vector<int>dp(n,-1);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(dp[i]==-1)
            {
                dp[i]=dfs(i,arr, d,dp);
            }
            ans=max(ans,dp[i]);
        }
        return(ans+1);
    }
};