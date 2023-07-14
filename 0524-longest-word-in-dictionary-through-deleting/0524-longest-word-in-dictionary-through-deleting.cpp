class Solution {
public:
   bool check(string a,string b)
   {
       int i=0,j=0;
       int total=0;
       while(i<a.size() && j<b.size())
       {
           if(a[i]==b[j])
           {
               total++;
               i++;
           }
           j++;
       }
       return(total==a.size());
   }
    string findLongestWord(string s, vector<string>& dictionary) {
        vector<string>dict;
        for(auto e:dictionary)
        {
            if(e.size()<=s.size())
               dict.push_back(e);
        }
        sort(dict.begin(),dict.end());
        string ans="";
        for(auto e:dict)
        {
            if(check(e,s) && ans.size()<e.size())
            {
                ans=e;
            }
        }
        return(ans);
    }
};