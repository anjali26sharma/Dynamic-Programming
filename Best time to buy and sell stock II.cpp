//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

//Top-down

class Solution {
public:
    
    int solve(vector<int> &prices, int isbuy, int ind, vector<vector<int>> &t)
    {   int n = prices.size(), profit =0;
        if(ind == n)
            return 0;
     if(t[ind][isbuy] != -1)
         return t[ind][isbuy];
     if(isbuy)
     {
         profit = max(-prices[ind] + solve(prices,0,ind+1,t), 0+solve(prices,1,ind+1,t));
     }
     else
     {
         profit = max(prices[ind]+solve(prices,1,ind+1,t), 0+solve(prices,0,ind+1,t));
     }
     return t[ind][isbuy] = profit;
    }
    int maxProfit(vector<int>& prices) {
       int n = prices.size();
        vector<vector<int>> t(n,vector<int>(2,-1));
        return solve(prices,1,0,t);
    }
};

//Bottom Up

class Solution {
public:
    
    
    int maxProfit(vector<int>& prices) {
       int n = prices.size();
        vector<vector<int>> t(n+1,vector<int>(2,0));
        for(int ind = n-1; ind>=0; ind--)
            for(int j =0; j<=1; j++)
            {
                if(j)
                t[ind][j] = max(-prices[ind] + t[ind+1][0] , t[ind+1][1]);
                else
                    t[ind][j] = max(prices[ind] + t[ind+1][1], t[ind+1][0]);
            }
        return t[0][1];
    }
};
