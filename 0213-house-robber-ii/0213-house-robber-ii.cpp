class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1)
            return(nums[0]);
        vector<int>dp1(n,0);
        dp1[n-2]=nums[n-2];
        
        for(int i=n-3;i>=0;i--)
        {
            dp1[i]=max(dp1[i+1],nums[i]+dp1[i+2]);
        }
          vector<int>dp2(n,0);
        dp2[n-1]=nums[n-1];
          dp2[n-2]=nums[n-1];
        for(int i=n-3;i>=1;i--)
        {
            dp2[i]=max(dp2[i+1],nums[i]+dp2[i+2]);
        }
        return(max(dp1[0],dp2[1]));
    }
};