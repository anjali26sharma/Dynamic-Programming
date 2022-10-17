//https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxi(int a, int b, int c)
    {
        if(a>=b && a>=c)
            return a;
        else if(b>=a && b>=c)
            return b;
        else return c;
    }
    int mini(int a , int b, int c)
    {
        if(a<=b && a<=c)
            return a;
        else if(b<=c && b<=a)
            return b;
        else return c;
    }
    int maxProduct(vector<int>& nums) {
        int currmax = nums[0],currmin = nums[0], best = nums[0];
        for(int i = 1;i<nums.size();i++)
        {
            int temp = nums[i]*currmax;
            currmax = maxi(temp,nums[i]*currmin,nums[i]);
            currmin = mini(temp,nums[i]*currmin,nums[i]);
            best = max(best,currmax);

            
        }
        return best;
    }
};
