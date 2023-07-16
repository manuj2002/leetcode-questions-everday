class Solution {
public:
    bool verify( vector<vector<int>>&first,vector<vector<int>>&last,int t,int n,int k)
    {
        for(int i=0;i<=t;i++)
        {
            int a=first[i][0]+last[n-t+i][0];
            int b=first[i][1]+last[n-t+i][1];
            int c=first[i][2]+last[n-t+i][2];
            if(a>=k && b>=k && c>=k)
                  return(true);
        }
        return(false);
    }
    int takeCharacters(string s, int k) {
        int n=s.size();
        vector<vector<int>>first(n+1,vector<int>(3,0));
         vector<vector<int>>last(n+1,vector<int>(3,0));
        for(int i=1;i<=n;i++)
        {
           first[i]=first[i-1];
            first[i][s[i-1]-'a']++;
        }
        for(int i=n-1;i>=0;i--)
        {
            last[i]=last[i+1];
            last[i][s[i]-'a']++;
        }
        int ans=-1;
        int l=0,h=n;
        while(l<=h)
        {
            int m=(l+h)/2;
            if(verify(first,last,m,n,k))
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