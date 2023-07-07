class Solution {
public:
    bool verify(vector<int>& bloomDay,int day,int m,int k)
    {
        int n=0;
    int i=-1;
        for(int j=0;j<bloomDay.size();j++)
        {
            if(bloomDay[j]<=day)
            {
                if(i==-1)
                    i=j;
                if((j-i+1)==k)
                {
                    n++;
                    i=-1;
                }
            }
            else
            {
                i=-1;
            }
        }
        return(n>=m);
        
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l=1,h=1e9;
        if( bloomDay.size()<((long long )m*k))
            return(-1);
        int ans=-1;
        while(l<=h)
        {
            int day=(l+h)/2;
            if(verify(bloomDay,day,m,k))
            {
                ans=day;
                h=day-1;
            }
            else
            {
                l=day+1;
            }
                
                
        }
        return(ans);
    }
};