https://leetcode.com/problems/target-sum/

class Solution {
public:
    int helper(vector<int> & nums, int n , int sum, vector<vector<int>> &t)
    {
        for(int i =0; i<n+1; i++)
            for(int j =0; j<sum+1; j++)
            {
                if(i==0)
                    t[i][j]=0;
                if(j==0)
                    t[i][j]=1;
            }
        for(int i =1; i<n+1; i++)
            for(int j =0; j<sum+1; j++)
            {
                if(nums[i-1]<=j)
                {
                    t[i][j] = t[i-1][j - nums[i-1]] + t[i-1][j];
                }
                else
                    t[i][j]= t[i-1][j];
            }
        return t[n][sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(),range =0;
        for(int i =0; i<n; i++)
            range+=nums[i];
        if(range < abs(target) || (range - target) %2 != 0) return 0;
        int sum = (range - target)/2;
        vector<vector<int>> t(n+2,vector<int>(sum+2));
        return helper(nums,n,sum,t);
    }
};
