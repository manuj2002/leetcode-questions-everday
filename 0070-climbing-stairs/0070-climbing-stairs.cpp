class Solution {
public:
    int climbStairs(int n) {
       int prev1=1;
        int prev2=1;
        for(int i=1;i<=n;i++)
        {
            int ans=0;
            ans+=prev1;
            if(i>=2)
            {ans+=prev2;
            prev2=prev1;}
            prev1=ans;
        }
        return(prev1);
    }
};