class Solution {
public:
    
     
    long long putMarbles(vector<int>& nums, int k) {
      if(nums.size()==k||k==1)
         return(0);
         priority_queue<long long >q1;
         priority_queue<long long ,vector<long long>,greater<long long> >q2;
         for(int i=0;i<nums.size()-1;i++)
         {
             if(i+1<nums.size())
             {
                 q1.push(nums[i]+nums[i+1]);
                 q2.push(nums[i]+nums[i+1]);
             }
         }
         long long  m1=0;
         long long  m2=0;
       k--;
         while(k-- &&  !q1.empty())
         {
             m1+=q1.top();
                 m2+=q2.top();
                 q1.pop();
                 q2.pop();
         }
         return(m1-m2);
    }
};