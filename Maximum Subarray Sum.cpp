
// 1. Recursion

class Solution {
public:
    
    int solve(int n, vector<int> &nums, int res[])
    {   
        if(n==0)
        { 
            res[0] = nums[0];
            return nums[0];
        }
        
        res[n] = max(nums[n],nums[n]+solve(n-1,nums,res));
        return res[n];
        
    }
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int res[n];
        int ans = solve(n-1,nums,res);
        int maxi = INT_MIN;
        for(int i =0 ;i<n; i++)
        {
            maxi = max(maxi,res[i]);
        }
        return maxi;
        
    }
};


// 2. Kadane's

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = nums[0];
        int best = nums[0];
        for(int i =1; i<nums.size();i++)
        {
            if(curr<0)
                curr= nums[i];
            else
                curr+=nums[i];
            best = max(best,curr);
        }
        return best;
    }
};
