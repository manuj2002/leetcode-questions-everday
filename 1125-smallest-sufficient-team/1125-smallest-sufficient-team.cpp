class Solution {
public:
    map<pair<long long ,long long >,long long>dp;
    long long  dfs(long long  i,long long  k,vector<vector<string>>& people, unordered_map<string,int>&rel,int n)
{
        
        if(dp.count({i,k})>0)
            return(dp[{i,k}]);
     
      long long m=(1LL<<n)-1;
    
        if(k==m)
            return(dp[{i,k}]=0);
          if(i==people.size())
            return(dp[{i,k}]=m);
      
       long long  c=k;
       long long  ans=(1LL<<people.size())-1;
        for(auto e:people[i])
        {
            c=(c|(1LL<<rel[e]));
            
        }
        long long  x=dfs(i+1,c,people,rel,n);
        long long y=dfs(i+1,k,people,rel,n);
        if((1+__builtin_popcountll(x))<__builtin_popcountll(ans))
        {
            ans=(x|(1LL<<i));
        }
        if(__builtin_popcountll(y)<__builtin_popcountll(ans))
        {
            ans=y;
        }
        return(dp[{i,k}]=ans);
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string,int>rel;
        int n=req_skills.size();
    for(int i=0;i<req_skills.size();i++)
    {
        rel[req_skills[i]]=i;
    }
        long long  mask=dfs(0,0,people,rel,n);
   
        vector<int>ans;
        
        for(long long  i=0;i<64;i++)
        {
            long long c=(1LL<<i);
            if((mask^(mask|c))==0)
                  ans.push_back(i);
        }
        return(ans);
        
    }
};