class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
       int time=0;
        queue<pair<int,int>>q;
        unordered_map<int,vector<int>>adj;
        for(auto e:edges)
        {
            adj[e[0]].push_back(e[1]);
             adj[e[1]].push_back(e[0]);
        }
        q.push({-1,1});
        vector<int>vis(n+1,0);
        vis[1]=-1;;
        unordered_map<int,pair<double,int>>track;
        track[1]={1.00,0};
        
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                int p=q.front().first;
                int i=q.front().second;
                double prob=track[i].first;
                q.pop();
                int denominator=adj[i].size();
                if(p!=-1)
                    denominator--;
                    
                for(auto e:adj[i])
                {
                    if(e!=p && vis[e]==0)
                    {
                        q.push({i,e});
                        vis[e]=i;
                        track[e]={(prob*(1.00/denominator)),time+1};
                    }
                }
            }
            time++;
        }
        cout<<track[target].second<<endl;
        if(t==track[target].second)
            return(track[target].first);
        
        if(t>track[target].second && ((adj[target].size()==1 && target!=1)||target==1 &&adj[target].size()==0) )
            return(track[target].first);
        return(0);
    }
};