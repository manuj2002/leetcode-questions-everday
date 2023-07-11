/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int>ans;
    vector<TreeNode*>track;
   
    void search(TreeNode* root,TreeNode* target,vector<TreeNode*>t)
    {
        if(!root)
            return;
        t.push_back(root);
        
        if(root==target)
        { track=t;
          return;}
          search(root->left,target,t);
        search(root->right,target,t);
        
        
    }
    void finalans(TreeNode* root,int d,TreeNode* target)
    {
        if(!root)
            return;
        if(d==0)
        {ans.push_back(root->val);
         return;}
        if(root->left!=target)
        finalans(root->left,d-1,target);
         if(root->right!=target)
        finalans(root->right,d-1,target);
        
        
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<TreeNode*>t;
        int j=0;
        search(root,target,t);
       int n= track.size();
        int i=n-1;
        track.push_back(NULL);
        while(i>=0 && k-j>=0)
        {
            finalans(track[i],k-j,track[i+1]);
            i--;
            j++;
        }
    
        
        return(ans);
        
    }
};