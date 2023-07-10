class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if(s.back()=='1')
            return(false);
        int n=s.size();
         vector<int>pre(n+1,0);
        pre[n-1]=1;
        int sum=1;
        for(int i=n-2;i>=0;i--)
        {
            if(s[i]=='0')
            {
                int j=i+minJump;
                if(j>=n && i==0)
                     return(false);
                int k=min(i+maxJump,n-1);
                if( j<n && pre[j]-pre[k+1]>0)
                {
                    sum++;
                    
                }
                if( j<n && pre[j]-pre[k+1]==0 && i==0)
                      return(false);
                
            }
            pre[i]=sum;
           
        }
        return(true);
    }
};