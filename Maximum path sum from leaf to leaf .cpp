//https://practice.geeksforgeeks.org/problems/maximum-path-sum/1

class Solution {
public:

    int solve(Node* root, int & res)
    {
        if(root == NULL)
        return 0;
         
         if(root->left == NULL && root->right == NULL)
         return root->data;
         int l = solve(root->left,res);
         int r = solve(root->right,res);
         if(root->left == NULL)
         return root->data +r;
         if(root->right == NULL)
         return root->data + l;
         int temp = max(l,r) + root->data;
         int ans = l+r+root->data;
         res = max(res,ans);
         return temp;
    }
    
    int maxPathSum(Node* root)
    {
        int res = INT_MIN;
        int ans = solve(root,res);
        if(root->left == NULL || root->right == NULL)
        return max(ans,res);
        return res;
    }
    
                                                                                                     
};
