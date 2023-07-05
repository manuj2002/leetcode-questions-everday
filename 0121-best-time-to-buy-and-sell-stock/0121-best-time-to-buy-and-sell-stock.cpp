class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int m=prices.back();
        for(int i=prices.size()-2;i>=0;i--)
        {
            ans=max(ans,m-prices[i]);
            m=max(prices[i],m);
        }
        return(ans);
    }
};