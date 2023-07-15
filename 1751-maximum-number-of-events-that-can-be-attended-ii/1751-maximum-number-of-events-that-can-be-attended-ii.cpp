class Solution {
public:
 
    int indexreq(int i,vector<vector<int>>& events)
    {
        int ans=events.size();
        int l=i+1;
       
        int n=events.size();
         int h=n-1;
        while(l<=h)
        {
            int m=(l+h)/2;
            
            if(events[m][0]>events[i][1])
            {
                ans=m;
                h=m-1;
            }
            else
            {
                l=m+1;
            }
        }
        return(ans);
    }
     int solve(int i,int k,vector<vector<int>>& events,vector<vector<int>>&dp)
     {
         if(dp[i][k]!=-1)
              return(dp[i][k]);
         int n=events.size();
         
         if(i==n ||k==0)
               return(dp[i][k]=0);
         int ans=events[i][2];
         int indx=indexreq(i,events);
         int j=indx;
         
             ans=max(ans,solve(j,k-1,events,dp)+events[i][2]);
           
         
         ans=max(ans,solve(i+1,k,events,dp));
         return(dp[i][k]=ans);
     }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
       int n=events.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return(solve(0,k,events,dp));
      
    }
};