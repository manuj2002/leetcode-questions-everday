class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX;
        int i=0;
        int s=0;
        for(int j=0;j<nums.size();j++)
        {
            s+=nums[j];
            while(i<=j && s>=target)
            {
                ans=min(ans,j-i+1);
                s-=nums[i];
                i++;
            }
        }
        if(ans==INT_MAX)
            return(0);
        return(ans);
    }
};