class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int currstep=0;
        int maxstep=0;
        int total_jump=0;
        for(int i=0;i<n;i++)
        {
            if(i>currstep)
            {
                currstep=maxstep;
                total_jump++;
                
            }
            maxstep=max(maxstep,i+nums[i]);
        }
        return(total_jump);
    }
};