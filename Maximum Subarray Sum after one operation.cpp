//https://leetcode.ca/2021-03-29-1746-Maximum-Subarray-Sum-After-One-Operation/

class Solution {
    public int maxSumAfterOperation(int[] nums) {
        int length = nums.length;
        int[][] dp = new int[length][3];
        dp[0][0] = nums[0];
        dp[0][1] = nums[0] * nums[0];
        dp[0][2] = INT_MIN;
        int maxi = dp[0][1];
        for (int i = 1; i < length; i++) {
            dp[i][0] = max(dp[i - 1][0], 0) + nums[i];
            dp[i][1] = max(dp[i - 1][0], 0) + nums[i] * nums[i];
            dp[i][2] = max(max(dp[i - 1][1], dp[i - 1][2]), 0) + nums[i];
            int curMax = max(dp[i][1], dp[i][2]);
            maxi = max(maxi, curMax);
        }
        return maxi;
    }
}
