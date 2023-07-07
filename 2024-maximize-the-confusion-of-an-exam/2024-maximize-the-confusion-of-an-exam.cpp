class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ans=0;
        int i=0,j=0;
        int n=answerKey.size();
        int no_f=0;
        for(;j<n;j++)
        {
            if(answerKey[j]=='F')
            {
                no_f++;
                
                while(no_f>k && i<j)
                {
                    if(answerKey[i]=='F')
                        no_f--;
                    i++;
                }
               
            }
             ans=max(ans,j-i+1);
        }
        ans=max(ans,j-i);
        i=0,j=0;
        int no_t=0;
          for(;j<n;j++)
        {
            if(answerKey[j]=='T')
            {
                no_t++;
                
                while(no_t>k && i<j)
                {
                    if(answerKey[i]=='T')
                        no_t--;
                    i++;
                }
               
            }
               ans=max(ans,j-i+1);
        }
        ans=max(ans,j-i);
        return(ans);
        
        
    }
};