class Solution {
public:
    long long maxTaxiEarnings(int N, vector<vector<int>>& rides) {
        sort(rides.begin(),rides.end());
        int n=rides.size();
        vector<long long>dp(n+1,0);
        dp[n-1]=rides[n-1][1]-rides[n-1][0]+rides[n-1][2];
       long long  m=dp[n-1];
        for(int i=n-2;i>=0;i--)
        {
            int l=i+1,h=n-1,pos=i;
            while(l<=h)
            {
                int m=(l+h)/2;
                if(rides[m][0]>=rides[i][1])
                {
                    h=m-1;
                    pos=m;
                }
                else
                {
                    l=m+1;
                }
            }
            if(pos==i && rides.back()[0]<pos)
            {
                pos=n ;
            }
            m=max(m,(rides[i][1]-rides[i][0]+rides[i][2]+dp[pos]));
            dp[i]=m;
            
            
            
        
        }
        return(dp[0]);
    }
};