//https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    
    int solve(int index , int prev, vector<int> &nums,vector<vector<int>> &t)
    {  
        
        if(index == nums.size())
            return 0;
        if(t[index][prev+1]!= -1)
            return t[index][prev+1];
        int len = solve(index+1, prev, nums,t);
        if(prev == -1 || nums[index]>nums[prev])
            len = max(len , 1+solve(index+1, index, nums,t));
        return t[index][prev+1] = len;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> t(n+1,vector<int>(n+1,-1));
        return solve(0,-1,nums,t);
    }
};
