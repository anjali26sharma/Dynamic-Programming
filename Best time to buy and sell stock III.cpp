//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

// Top-Down

class Solution {
public:
    
    int solve(vector<int> &prices, int ind, int isbuy, int cap, vector<vector<vector<int>>> &t)
    {   int profit = 0;
        if(cap == 0)
            return 0;
        if(ind == prices.size())
            return 0;
        if(t[ind][isbuy][cap] != -1)
            return t[ind][isbuy][cap];
        if(isbuy)
        {
            profit = max(-prices[ind] + solve(prices,ind+1, 0, cap, t), 0 + solve(prices,ind+1,1,cap,t));
        }
        else
        {
            profit = max(prices[ind]+solve(prices,ind+1,1,cap-1,t), 0+ solve(prices,ind+1,0,cap,t));
        }
        return t[ind][isbuy][cap] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> t(n+1,vector<vector<int>> (2, vector<int>(3,-1)));
        return solve(prices,0,1,2,t);
    }
};

//Bottom up

class Solution {
public:
    
 int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> t(n+1,vector<vector<int>> (2, vector<int>(3,0)));
        for(int ind = n-1; ind >=0; ind--)
            for(int isbuy =0; isbuy <=1; isbuy++)
                for(int cap = 1; cap<=2; cap++)
                {
                    if(isbuy)
                    {
                        t[ind][isbuy][cap] = max(-prices[ind] + t[ind+1][0][cap], 0 + t[ind+1][1][cap]);
                    }
                    else
                    {
                        t[ind][isbuy][cap] = max(prices[ind]+t[ind+1][1][cap-1], 0+ t[ind+1][0][cap]);
                    }
                }
        return t[0][1][2];
  }
};
