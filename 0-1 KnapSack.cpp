class Solution
{
    public:
    
    
    //Function to return max value that can be put in knapsack of capacity W.
    int helper(int W, int wt[], int val[], int n, vector<vector<int>> &t)
    {
        for(int i =0; i< n+1 ; i++)
        for(int j =0; j<W+1; j++)
        if(i == 0 || j == 0)
        t[i][j]=0;
        for(int i =1; i< n+1 ; i++)
        {
         for(int j =1; j<W+1; j++)
         {
            if(wt[i-1]<=j)
           {
             t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]],t[i-1][j]);
           }
           else if(wt[i-1]>j)
           t[i][j]= t[i-1][j];
         }
        }
        return t[n][W];
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
      vector<vector<int>>t(n+2,vector<int>(W+2,-1));
      int ans = helper(W,wt,val,n,t);
      return ans;
    }
