class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        map<vector<int>,int>track;
        for(auto e:coordinates)
        {
            int d[][2]={{-1,0},{-1,-1},{0,-1},{0,0}};

            for(int k=0;k<4;k++)
            {
                 vector<int>v=e;
                  v[0]+=d[k][0];
                     v[1]+=d[k][1];
                 if(v[0]>=0 && v[1]>=0 && v[1]+1<n && v[0]+1<m)
                 {
                    
                     track[v]++;
                 }
            }

        }
         vector<long long >ans(5,0);
        long long total=(long long)(m-1)*(n-1);
      
        ans[0]=total-track.size();
        for(auto e:track)
        {
            ans[e.second]++;
        }
        
        
         return(ans);

    }
};