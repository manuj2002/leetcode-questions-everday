class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        unordered_map<int,int>key;
        unordered_map<int,int>vis;
        unordered_map<int,int>unlock;
     
        queue<int>q;
    
        for(auto e:initialBoxes)
        {
            if(status[e]==1)
             { q.push(e);
              vis[e]++;}
              else
              {
                  unlock[e]++;
              }
              
              
        }
        int ans=0;
        while(!q.empty())
        {
            int p=q.front();
            q.pop();
            ans+=candies[p];
            for(auto e:keys[p])
                key[e]++;
             for(auto e:containedBoxes[p])
             {
                 if(vis.count(e)==0 && (status[e]==1||(key.count(e)>0)))
                 {
                     vis[e]++;
                     q.push(e);
                 }
                 if(vis.count(e)==0 && status[e]==0 && key.count(e)==0)
                      unlock[e]++;
                
             }
             for(auto e:unlock)
             {
                 if(vis.count(e.first)==0 && key.count(e.first)>0)
                 {
                     vis[e.first]++;
                     q.push(e.first);
                 }
             }
            

        }
   
       
        return(ans);
    }
};