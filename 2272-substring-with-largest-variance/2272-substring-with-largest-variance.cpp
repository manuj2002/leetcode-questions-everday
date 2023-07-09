class Solution {
public:
   
    int largestVariance(string s) {
        vector<int>fre(26,0);
        for(auto e:s)
           fre[e-'a']++;
        int ans=0;
           for(int i=0;i<26;i++)
           {
               if(fre[i]==0)
                   continue;
               for(int j=0;j<26;j++)
               {
                     if (i == j || fre[i] == 0 ||fre[j] == 0) {
                    continue;
                }
               
                     char major = 'a' + i;
                char minor = 'a' + j;
                   int restMinor = fre[j];
                int majorCount = 0;
                int minorCount = 0;
                     for (char ch : s) {    
                    if (ch == major) {
                        majorCount++;
                    }
                    if (ch == minor) {
                        minorCount++;
                        restMinor--;
                    }
                    
                    // Only update the variance (local_max) if there is at least one minor.
                    if (minorCount > 0)
                      ans= max(ans, majorCount - minorCount);
                    
                    // We can discard the previous string if there is at least one remaining minor
                    if (majorCount < minorCount && restMinor > 0) {
                        majorCount = 0;
                        minorCount = 0;
                    }
                }
               
           }
           }
        return(ans);
    }
};