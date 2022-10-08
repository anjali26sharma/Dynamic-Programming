//https://leetcode.com/problems/largest-divisible-subset/

class Solution {
public:
    
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size(),maxi = 1,lastindex=0;
            vector<int> ans(n,1), hash(n);
            for(int  index = 0; index<n; index++)
            {
                hash[index] = index;
                for(int prev = 0; prev<index ; prev++)
                {
                    if(nums[index]% nums[prev] == 0 && ans[index] < 1+ans[prev])
                    {
                        ans[index] = 1+ ans[prev];
                        hash[index] = prev;
                    }
                }
                if(ans[index]> maxi)
                {
                    maxi = ans[index];
                    lastindex = index;
                }
            }
        vector<int> res;
            res.push_back(nums[lastindex]) ;
            
            while(hash[lastindex]!=lastindex)
            {
                lastindex = hash[lastindex];
                res.push_back(nums[lastindex]);
            }
            
            
            reverse(res.begin(),res.end());
            return res;
            
    }
};
