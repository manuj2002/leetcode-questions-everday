class Solution {
public:
 map<pair<int,int>,bool>dp;
    bool dfs(int i,int j,string &s, string &p)
    {
        if(dp.count({i,j})>0)
            return(dp[{i,j}]);
        if(i==s.size() && j==p.size())
            return(dp[{i,j}]=true);
        if(i==s.size())
            return(dp[{i,j}]=false);
        if(j==p.size() && s[i]=='*')
            return(dp[{i,j}]=dfs(i+1,j,s,p));
        if(j==p.size())
            return(dp[{i,j}]=false);
        if(s[i]==p[j] ||s[i]=='?')
             return(dp[{i,j}]=dfs(i+1,j+1,s,p));
         if(s[i]!=p[j] && s[i]!='*')
             return(dp[{i,j}]=false);
        bool ans=false;
        ans=ans||dfs(i+1,j,s,p);
   
        ans=ans||dfs(i,j+1,s,p);
        return(dp[{i,j}]=ans);
    }
    bool isMatch(string s, string p) {
        
        return(dfs(0,0,p,s));
    }
};