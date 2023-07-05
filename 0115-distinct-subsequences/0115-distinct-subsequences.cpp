class Solution {
public:
    int dfs(int i,int j,string &s,string &t,vector<vector<int>>&dp)
    {
        if(dp[i][j]!=-1)
            return(dp[i][j]);
        if(i==s.size() && j==t.size())
            return(dp[i][j]=1);
        if(i==s.size())
            return(dp[i][j]=0);
          if(j==t.size())
              return(dp[i][j]=dfs(i+1,j,s,t,dp));
        int ans=0;
        if(s[i]==t[j])
            ans+=dfs(i+1,j+1,s,t,dp);
        ans+=dfs(i+1,j,s,t,dp);
        return(dp[i][j]=ans);
        
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return(dfs(0,0,s,t,dp));
    }
};