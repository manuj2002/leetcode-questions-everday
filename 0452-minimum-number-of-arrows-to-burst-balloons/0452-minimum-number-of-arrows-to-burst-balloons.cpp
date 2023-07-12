class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int l=points[0][0];
        int h=points[0][1];
        int ans=1;
        for(int i=1;i<points.size();i++)
        {
            if( h>=points[i][0])
            {
                l=points[i][0];
                h=min(h,points[i][1]);
            }
            else
            {
                ans++;
                l=points[i][0];
                h=points[i][1];
            }
        }
        return(ans);
        
        

    }
};