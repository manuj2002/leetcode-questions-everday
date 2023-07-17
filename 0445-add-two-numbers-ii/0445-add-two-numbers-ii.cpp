/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
     ListNode* reverse(ListNode* l)
     {
         ListNode* prev=NULL;
        ListNode * curr=l;
         ListNode* next=NULL;
         while(curr!=NULL)
         {
             next=curr->next;
             curr->next=prev;
             prev=curr;
             curr=next;
         if(next==NULL)
             l=prev;
             
         }
         return(l);
     }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverse(l1);
        l2=reverse(l2);
        ListNode* ans=NULL;
          ListNode* track=NULL;
        
        int c=0;
        while(l1!=NULL ||l2!=NULL)
        {
            int p1=0,p2=0;
            if(l1!=NULL)
            { p1=l1->val;
            l1=l1->next;}
              if(l2!=NULL)
            { p2=l2->val;
            l2=l2->next;}
            
            if(ans==NULL)
            {
               track=new ListNode;
                track->val=(p1+p2+c)%10;
                
                c=(p1+p2+c)/10;
                ans=track;
                
            }
            else
            {
                track->next=new ListNode((p1+p2+c)%10);
                c=(p1+p2+c)/10;
                track=track->next;
            }
                
        }
        if(c>0)
        {
            track->next=new ListNode(c);
               track=track->next;
             
        }
        ans=reverse(ans);
        return(ans);
    }
};