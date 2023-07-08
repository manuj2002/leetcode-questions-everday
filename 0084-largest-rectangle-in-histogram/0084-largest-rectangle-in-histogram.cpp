class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>s;
        vector<int>store1(heights.size(),1);
        for(int i=0;i<=heights.size();i++)
        {
            while(!s.empty() && (i==heights.size()||heights[s.top()]>heights[i]))
            {
                store1[s.top()]=i-s.top()-1;
                s.pop();

            }
            s.push(i);
        }
        s.pop();
         int ans=0;
         for(int i=heights.size()-1;i>=-1;i--)
        {
            while(!s.empty() && (i==-1||heights[s.top()]>heights[i]))
            {
                store1[s.top()]+=(s.top()-i);
                ans=max(ans,heights[s.top()]*store1[s.top()]);
                s.pop();

            }
           
            
            s.push(i);
        }
       
        return(ans);

    }
};