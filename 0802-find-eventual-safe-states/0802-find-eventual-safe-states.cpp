class Solution {
public:
  bool dfs(int i,unordered_map<int,vector<int>>&adj,vector<int>&state)
  {
      if(state[i]!=0)
      {
          return(state[i]==2);
      }
      state[i]=1;
      
      int t=0;
      for(auto e:adj[i])
      {
          if(!dfs(e,adj,state))
              t++;
      }
     if(adj[i].empty() || t==0)
      {
          state[i]=2;
          return(true);
      }
     
      return(false);
         
  }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>state(n,0);
      unordered_map<int,vector<int>>adj;
      for(int i=0;i<n;i++)
      {
          for(auto e:graph[i])
              adj[i].push_back(e);
      }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(state[i]==0)
                dfs(i,adj,state);
            if(state[i]==2)
                ans.push_back(i);
        }
        return(ans);
        
    }
};