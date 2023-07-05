class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<m;j++)
            {
                int ans=INT_MAX;
                if(j-1>=0)
                    ans=min(ans,matrix[i][j]+matrix[i+1][j-1]);
                        ans=min(ans,matrix[i][j]+matrix[i+1][j]);
                if(j+1<m)
                     ans=min(ans,matrix[i][j]+matrix[i+1][j+1]);
                  matrix[i][j]=ans;
            }
        }
        int ans=INT_MAX;
        for(auto e:matrix[0])
            ans=min(ans,e);
        return(ans);
    }
        
};