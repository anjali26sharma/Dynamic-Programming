class Solution
{
    public:
    
    
    //Function to return max value that can be put in knapsack of capacity W.
    int helper(int W, int wt[], int val[], int n, vector<vector<int>> &t)
    {
        if(W ==0 || n ==0)
      return 0;
      if(t[n][W] != -1)
      return t[n][W];
      if(wt[n-1]<=W)
      return t[n][W] = max(val[n-1]+helper(W-wt[n-1],wt,val,n-1,t),helper(W,wt,val,n-1,t));
      if(wt[n-1]>W)
      return t[n][W] = helper(W,wt,val,n-1,t);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
      vector<vector<int>>t(n+2,vector<int>(W+2,-1));         // matrix t initialized as -1
      int ans = helper(W,wt,val,n,t);
      return ans;
    }
};
