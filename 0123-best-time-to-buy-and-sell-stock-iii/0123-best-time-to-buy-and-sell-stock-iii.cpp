class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>dp_after(n,0);
        int ma=prices.back();
        for(int i=n-2;i>=0;i--)
        {
            ma=max(ma,prices[i]);
            dp_after[i]=max(ma-prices[i],dp_after[i+1]);
        }
           vector<int>dp_before(n,0);
        int mi=prices[0];
            for(int i=1;i<prices.size();i++)
            {
                mi=min(mi,prices[i]);
                dp_before[i]=max(prices[i]-mi,dp_before[i-1]);
            }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,dp_after[i]+dp_before[i]);
        }
        return(ans);
    }
};