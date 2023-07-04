class Solution {
public:
int dfs(int i,int j,string &word1,string & word2,vector<vector<int>>&dp)
{
    if(dp[i][j]!=-1)
       return(dp[i][j]);
    if(i==word1.size() && j==word2.size())
         return(dp[i][j]=0);
         if(i==word1.size())
         {
             return(dp[i][j]=1+dfs(i,j+1,word1,word2,dp));
         }
         if(j==word2.size())
         {
              return(dp[i][j]=1+dfs(i+1,j,word1,word2,dp));
         }
         if(word1[i]==word2[j])
         {
             return(dp[i][j]=dfs(i+1,j+1,word1,word2,dp));
         }
         int insertl=1+dfs(i,j+1,word1,word2,dp);
         int deletel=1+dfs(i+1,j,word1,word2,dp);
         int replacel=1+dfs(i+1,j+1,word1,word2,dp);
         return(dp[i][j]=min(insertl,min(deletel,replacel)));
}

    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        return(dfs(0,0,word1,word2,dp));
    }
};