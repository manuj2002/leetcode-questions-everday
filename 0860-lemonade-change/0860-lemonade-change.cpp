class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f=0,t=0,tw=0;
        for(auto e:bills)
        {
             if(e==5)
             {
                 f++;
             }
            else if(e==10)
            {
                if(f==0)
                    return(false);
                f--;
                t++;
            }
            else
            {
                
                if(t>0 && f>0)
                {
                    t--;
                    f--;
                    tw++;
                }
                else if(f>=3)
                {
                    f-=3;
                    tw++;
                }
                else
                {
                    return(false);
                }
            }
        }
            
            
            
            return(true);
    }
};