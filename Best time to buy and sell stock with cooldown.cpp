//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int n = prices.size();
        vector<vector<int>> t(n+2,vector<int>(2,0));                                // n+2 because we are doing ind+2 below, else it will give segmentation fault
        for(int ind = n-1; ind>=0; ind--)
            for(int j =0; j<=1; j++)
            {
                if(j)
                t[ind][j] = max(-prices[ind] + t[ind+1][0] , t[ind+1][1]);
                else
                    t[ind][j] = max(prices[ind] + t[ind+2][1], t[ind+1][0]);     // ind+2 when we're selling
            }
        return t[0][1];
    }
};
