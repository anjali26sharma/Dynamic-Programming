//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

//Bottom up

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
         
        int n = prices.size();
        vector<vector<vector<int>>> t(n+1,vector<vector<int>> (2, vector<int>(k+1,0)));
        for(int ind = n-1; ind >=0; ind--)
            for(int isbuy =0; isbuy <=1; isbuy++)
                for(int cap = 1; cap<=k; cap++)
                {
                    if(isbuy)
                    {
                        t[ind][isbuy][cap] = max(-prices[ind] + t[ind+1][0][cap], 0 + t[ind+1][1][cap]);
                    }
                    else
                    {
                        t[ind][isbuy][cap] = max(prices[ind]+t[ind+2][1][cap-1], 0+ t[ind+1][0][cap]);
                    }
                }
        return t[0][1][k];
    }
    
};
