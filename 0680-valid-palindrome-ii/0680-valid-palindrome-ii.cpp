class Solution {
public:
    bool dfs(int i ,int j,string s)
    {
        while(i<=j)
        {
            if(s[i]!=s[j])
                return(false);
            i++;
            j--;
        }
        return(true);
    }
    bool validPalindrome(string s) {
        int i=0,j=s.size()-1;
        while(i<=j)
        {
            if(s[i]!=s[j])
            {
               
                       return(dfs(i+1,j,s)||dfs(i,j-1,s));
            }
            i++;
            j--;
        }
        return(true);
    }
};