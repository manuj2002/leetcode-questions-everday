class Solution {
public:
    int totalislands(vector<vector<int>>& grid,pair<int,int>p)
    {
        int n=grid.size();
        int m=grid[0].size();
        int total=0;

        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                pair<int,int>p1={i,j};
                if(grid[i][j]==1 && dp[i][j]==0 && p!=p1)
                {
                    total++;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    dp[i][j]++;
                    while(!q.empty())
                    {
                        int i1=q.front().first;
                        int j1=q.front().second;
                        q.pop();
                       
                        int d[][2]={{0,1},{1,0},{-1,0},{0,-1}};
                        for(int k=0;k<4;k++)
                        {
                            int i2=i1+d[k][0];
                            int j2=j1+d[k][1];
                            p1.first=i2;
                            p1.second=j2;
                            if(j2>=0 && i2>=0 && i2<n && j2<m && grid[i2][j2]==1 &&dp[i2][j2]==0 && p!=p1) 
                            {
                                q.push({i2,j2});
                            dp[i2][j2]++; 
                            }
                        }
                    }
                }
            }
        }
        return(total);
    }
    int minDays(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int total=0;
       vector<pair<int,int>>track;
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && dp[i][j]==0)
                {
                    total++;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    dp[i][j]++;
                    while(!q.empty())
                    {
                        int i1=q.front().first;
                        int j1=q.front().second;
                        q.pop();
                        track.push_back({i1,j1});
                        int d[][2]={{0,1},{1,0},{-1,0},{0,-1}};
                        for(int k=0;k<4;k++)
                        {
                            int i2=i1+d[k][0];
                            int j2=j1+d[k][1];
                            if(j2>=0 && i2>=0 && i2<n && j2<m && grid[i2][j2]==1 &&dp[i2][j2]==0) 
                            {
                                q.push({i2,j2});
                            dp[i2][j2]++; 
                            }
                        }
                    }
                }
            }
        }
        if(total!=1)
            return(0);
        for(int i=0;i<track.size();i++)
        {
            pair<int,int>p=track[i];
            if(totalislands(grid,p)!=1)
                  return(1);
        }
       
            return(2);
    }
};