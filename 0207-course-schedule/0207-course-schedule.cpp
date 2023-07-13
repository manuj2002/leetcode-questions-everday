class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<int>in(numCourses,0);
        for(auto e:prerequisites)
        {
            adj[e[0]].push_back(e[1]);
            in[e[1]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(in[i]==0)
                q.push(i);
        }
        int total=0;
        while(!q.empty())
        {
            total++;
            int p=q.front();
            q.pop();
            for(auto e:adj[p])
            {
                if(in[e]>0)
                {
                 in[e]--;
                }
                if(in[e]==0)
                {
                    q.push(e);
                }
                    
            }
        }
        return(total==numCourses);
    }
};