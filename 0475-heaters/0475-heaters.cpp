class Solution {
public:
    bool verify(vector<int>& houses,vector<int>& heaters,int r)
    {
        int l=0,h=0,i=0,n=heaters.size(),total=0;
        for(int j=0;j<houses.size();j++)
        {
            while(i<n && (!(l<=houses[j] && h>=houses[j])))
            {
                l=heaters[i]-r;
                h=heaters[i]+r;
                i++;
            }
            if(l<=houses[j] && h>=houses[j])
                total++;
        }
        return(total==houses.size());
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
         int l=0;
        int h=1e9;
        int ans=-1;
        while(l<=h)
        {
            int m=(l+h)/2;
            if(verify(houses,heaters,m))
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
};