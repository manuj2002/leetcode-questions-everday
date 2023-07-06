class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int>pre;
        pre.push_back(0);
        for(auto e:nums)
            pre.push_back(pre.back()+e);
        int ans=INT_MAX,n=nums.size();
        for(int i=0;i<n;i++)
        {
           int l=i,h=n-1;
            int indx=-1;
            while(l<=h)
            {
                int m=(l+h)/2;
                if(pre[m+1]-pre[i]>=target)
                {
                    indx=m;
                    h=m-1;
                }
                else
                {
                    l=m+1;
                }
            }
            if(indx!=-1)
                ans=min(ans,indx-i+1);
          
        }
        if(ans==INT_MAX)
            return(0);
        return(ans);
    }
};