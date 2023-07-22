class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n=security.size();
        vector<int>increasing(n,0);
        for(int i=1;i<n;i++)
        {
            if(security[i-1]>=security[i])
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
            if(security[i+1]>=security[i])
            {
                decreasing[i]=decreasing[i+1];
            }
            else
            {
               decreasing[i]=i;
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(i-time>=increasing[i] && i+time<=decreasing[i])
                 ans.push_back(i);
        }
        return(ans);
        
            
    }
};