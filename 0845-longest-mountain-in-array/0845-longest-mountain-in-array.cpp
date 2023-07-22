class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        vector<int>increasing(n,0);
        for(int i=1;i<n;i++)
        {
            if(arr[i-1]<arr[i])
            {
                increasing[i]=increasing[i-1];
            }
            else
            {
                 increasing[i]=i;
            }
        }
            vector<int>decreasing(n,0);
             decreasing[n-1]=n-1;
        for(int i=n-2;i>=0;i--)
        {
             if(arr[i+1]<arr[i])
            {
                decreasing[i]=decreasing[i+1];
            }
            else
            {
                 decreasing[i]=i;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(i-increasing[i]>0 && decreasing[i]-i>0 && decreasing[i]-increasing[i]+1>=3)
            {
                ans=max(ans,decreasing[i]-increasing[i]+1);
            }
        }
        return(ans);
    }
};