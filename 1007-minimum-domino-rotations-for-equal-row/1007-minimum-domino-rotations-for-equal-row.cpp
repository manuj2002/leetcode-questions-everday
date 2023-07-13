class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size();
        unordered_map<int,int>m1;
        unordered_map<int,int>m2;
         unordered_map<int,int>m3;
        for(int i=0;i<n;i++)
        {
            m1[tops[i]]++;
            m2[bottoms[i]]++;
            if(tops[i]==bottoms[i])
                m3[tops[i]]++;
            
        }
        int ans=INT_MAX;
        for(auto e:m1)
        {
           
            if(m2.count(e.first)>0 && e.second+m2[e.first]-m3[e.first]==n)
            {
                ans=min(ans,min(e.second-m3[e.first],m2[e.first]-m3[e.first]));
            }
        }
        if(ans==INT_MAX)
             return(-1);
        return(ans);
    }
};