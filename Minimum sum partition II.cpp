https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1

class Solution{
    
  public:
  int minDiff(int arr[], int n, int lsum, int rsum, vector<vector<int>> & dp){
      if(n==0) return abs(lsum - rsum);
      if(dp[n][lsum]!=-1) return dp[n][lsum]; 
      return dp[n][lsum] = min(minDiff(arr, n-1, lsum-arr[n-1], rsum+arr[n-1],dp), minDiff(arr, n-1, lsum, rsum, dp));   // returning minimum of :- min diff between s1 and s2 when we include last element of array in left array(s1) and when we include it in right array(s2).
  }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum = 0;
	    for(int i=0; i<n; i++)
	        sum = sum + arr[i];
	    vector<vector<int>> dp(n+2, vector<int>(sum+2, -1));
	    return minDiff(arr, n, sum, 0, dp);
	    
	} 
};
