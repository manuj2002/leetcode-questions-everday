class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l=-1;
        int h=-1;
        vector<pair<int,int>>arr;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                h=i;
                if(l==-1)
                    l=i;
            }
            else
            {
                if(l!=-1)
                {
                    arr.push_back({l,h});
                    l=-1;
                    h=-1;
                }
            }
        }
        if(l!=-1)
        {
             arr.push_back({l,h});
        }
        
          int ans=0;
        if(arr.size()==0)
             return(0);

        for(int i=0;i<arr.size();i++)
        {
            if( i>0 && arr[i].first-arr[i-1].second==2)
            {
                ans=max(ans,(arr[i].second-arr[i-1].first));
            }
          int L=arr[i].second-arr[i].first;
            if(arr[i].first>0 || arr[i].second<=nums.size()-2)
                L++;
            ans=max(L,ans);
        }
        return(ans);

    }
};