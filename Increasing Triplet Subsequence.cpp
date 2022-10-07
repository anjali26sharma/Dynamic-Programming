//https://leetcode.com/problems/increasing-triplet-subsequence/

class Solution {
public:
     
    
    int LIS(vector<int>& nums) {
        int len;
        vector<int> temp;
        temp.push_back(nums[0]);
        len = 1;
        for(int i = 1; i< nums.size();i++)
        {
            if(nums[i]>temp.back())
            {   temp.push_back(nums[i]);
                len++; 
            }
            else
            { auto ind = lower_bound(temp.begin(),temp.end(),nums[i]);
              temp[ind - temp.begin()] = nums[i];
            }
        }
        return len;
    }
    
    bool increasingTriplet(vector<int>& nums) {
        int n = LIS(nums);
        if(n>=3)
            return true;
        else return false;
    }
};
