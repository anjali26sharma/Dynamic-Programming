//https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/

class Solution {
public:
   
    int maxAbsoluteSum(vector<int>& nums) {
       int curr=nums[0],best1= nums[0],best2 = nums[0];
        for(int i =1; i<nums.size();i++)
        {
            if(curr>0)
                curr+=nums[i];
            else
                curr= nums[i];
            best1 = max(best1,curr);
        }
        curr = nums[0];
        for(int i =1; i<nums.size();i++)
        {
            if(curr<0)
                curr += nums[i];
            else
                curr = nums[i];
            best2 = min(best2,curr);
        }
        return max(best1,abs(best2));
    }
};
