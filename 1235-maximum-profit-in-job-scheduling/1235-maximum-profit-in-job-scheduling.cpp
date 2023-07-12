class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<pair<int,pair<int,int>>>arr;
        for(int i=0;i<n;i++)
        {
            arr.push_back({startTime[i],{endTime[i],profit[i]}});
        }
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++)
        {
            startTime[i]=arr[i].first;
            endTime[i]=arr[i].second.first;
            profit[i]=arr[i].second.second;
        }
        vector<int>dp(n+1,0);
        dp[n-1]=profit[n-1];
        for(int i=n-2;i>=0;i--)
        {
        int indx=lower_bound(startTime.begin()+i+1,startTime.end(),endTime[i])-startTime.begin();
            dp[i]=max(dp[i+1],dp[indx]+profit[i]);
        }
        return(dp[0]);
    }
};