class Solution {
public:
    map<pair<int,int>,int>dp;
    int dfs(int i,int j,string &s)
    {
        if(dp.count({i,j})>0)
             return(dp[{i,j}]);
        if(i>j)
            return(dp[{i,j}]=0);
        if(i==j)
            return(dp[{i,j}]=1);
        
        if(s[i]==s[j])
            return(dp[{i,j}]=2+dfs(i+1,j-1,s));
        return(dp[{i,j}]=max(dfs(i+1,j,s),dfs(i,j-1,s)));
    }
    int longestPalindromeSubseq(string s) {
        
        return(dfs(0,s.size()-1,s));
    }
};