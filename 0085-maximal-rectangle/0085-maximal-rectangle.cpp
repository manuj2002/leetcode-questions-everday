class Solution {
public:
int histogram(vector<int>&heights)
{
    stack<int>s;
        vector<int>store1(heights.size(),1);
        for(int i=0;i<=heights.size();i++)
        {
            while(!s.empty() && (i==heights.size()||heights[s.top()]>heights[i]))
            {
                store1[s.top()]=i-s.top()-1;
                s.pop();

            }
            s.push(i);
        }
        s.pop();
         int ans=0;
         for(int i=heights.size()-1;i>=-1;i--)
        {
            while(!s.empty() && (i==-1||heights[s.top()]>heights[i]))
            {
                store1[s.top()]+=(s.top()-i);
                ans=max(ans,heights[s.top()]*store1[s.top()]);
                s.pop();

            }
           
            
            s.push(i);
        }
       
        return(ans);

}
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int >>dp(matrix.size(),vector<int>(matrix[0].size(),0));
        int ans=0;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(i-1>=0)
                {
                    if(matrix[i][j]=='1')
                    {
                        dp[i][j]=dp[i-1][j]+1;
                    }
                    
                }
                else
                {
                  dp[i][j]=matrix[i][j]-'0';
                }
            }
            ans=max(ans,histogram(dp[i]));
        }
        return(ans);
    }
};