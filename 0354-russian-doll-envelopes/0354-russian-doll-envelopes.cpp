class Solution {
public:
    bool static cmp(vector<int>&a,vector<int>&b)
    {
        if(a[0]==b[0])
            return(a[1]>b[1]);
        return(a[0]<b[0]);
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),cmp);
        vector<int>v;
        v.push_back(envelopes[0][1]);
        for(int i=0;i<envelopes.size();i++)
        {
            if(v.back()<envelopes[i][1])
            {
                v.push_back(envelopes[i][1]);
            }
            else
            {
                int indx=lower_bound(v.begin(),v.end(),envelopes[i][1])-v.begin();
                v[indx]=envelopes[i][1];
            }
        }
        return(v.size());
    }
};