class Solution {
public:
vector<vector<vector<double>>>dp;
    Solution()
    {
        dp.resize(26,vector<vector<double>>(26,vector<double>(101,-1.000)));
    }
    double knightProbability(int n, int K, int row, int column) {
        if(dp[row][column][K]!=-1)
              return(dp[row][column][K]);
        if(K==0)
            return(dp[row][column][K]=1);
      double ans=0;
        int d[][2]={{1,2},{-1,2},{-1,-2},{1,-2},{2,1},{2,-1},{-2,-1},{-2,1}};
        for(int i=0;i<8;i++)
        {
            int row1=row+d[i][1];
            int column1=column+d[i][0];
            if(row1>=0 && column1>=0 && row1<n && column1<n)
            {
                ans+=(0.125*(knightProbability(n,K-1,row1,column1)));
            }
        }
        return(dp[row][column][K]=ans);
    }
};