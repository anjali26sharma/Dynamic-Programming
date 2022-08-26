https://leetcode.com/problems/maximum-length-of-repeated-subarray/

class Solution {
public:
    int helper(vector<int>& nums1, vector<int>& nums2, int n , int m, vector<vector<int>> &t)
    {
        for(int i =0; i<n+1; i++)
            for(int j =0; j< m+1; j++)
            {
                if(i==0 || j==0)
                    t[i][j] =0;
            }
        for(int i =1; i<n+1; i++)
            for(int j =1; j< m+1; j++)
            {
                if(nums1[i-1]==nums2[j-1])
                    t[i][j] = 1+ t[i-1][j-1];
                else
                    t[i][j]=0;
            }
        int mx = INT_MIN;
        for(int i =0; i<n+1; i++)
            for(int j =0; j< m+1; j++)
                mx = max(mx,t[i][j]);
        return mx;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> t(n+1,vector<int>(m+1,-1));
        int ans = helper(nums1,nums2,n,m,t);
        return ans;
    }
};
