class Solution {
public:
   map<pair<int,int>,int>dp; 
    int dfs(int curr,int copy,int n)
    {
        if(dp.count({curr,copy})>0)
             return(dp[{curr,copy}]);
        if(curr==n)
             return(dp[{curr,copy}]=0);
        if(curr>n)
            return(dp[{curr,copy}]=INT_MAX);
        int ans=INT_MAX;
        if(curr!=copy)
        {
            int x=dfs(curr,curr,n);
            if(x!=INT_MAX)
                ans=min(ans,1+x);
               
        }
        if(copy!=0)
        {int y=dfs(curr+copy,copy,n);
        if(y!=INT_MAX)
                ans=min(ans,1+y);}
        
        return(dp[{curr,copy}]=ans);
        
    }
    int minSteps(int n) {
        
        return(dfs(1,0,n));
    }
};