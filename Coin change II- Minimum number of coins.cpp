https://leetcode.com/problems/coin-change/

class Solution {
public:
    int min(int a, int b)
    {
        if(a<b)
            return a;
        else return b;
    }
    int helper(vector<int> &nums, int sum, int n , vector<vector<int>> &t)
    {
        for(int i =0; i<n+1; i++ )
            for(int j =0; j<sum+1; j++)
            {
                if(i==0)
                    t[i][j] = INT_MAX-1;
                if(j==0)
                    t[i][j] = 0;
            }
        for(int j =1; j< sum+1; j++)
        {
            if( j % nums[0]  !=0)
                t[1][j] = INT_MAX-1;
            else 
                t[1][j] = j/ nums[0];
        }
        t[0][0] = INT_MAX -1;
        for(int i = 2; i<n+1; i++)
            for(int j = 1; j<sum+1; j++)
            {
                if(nums[i-1]<=j)
                    t[i][j] = min(1+t[i][j-nums[i-1]], t[i-1][j]);
                else if(nums[i-1]>j)
                    t[i][j] = (t[i-1][j]);
            }
        return t[n][sum];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> t(n+2,vector<int>(amount+2,-1));
        int ans = helper(coins,amount,n,t);
        if(ans == INT_MAX-1)
           return -1;
           else return ans;
    }
};
