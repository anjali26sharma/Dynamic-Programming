https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1

class Solution{

	public:
	int helper(int nums[], int sum, int n, vector<vector<int>>t)
    {   int mod = 1e9+7;
        for(int i =0; i<n+1; i++ )
            for(int j =0; j<sum+1; j++)
            {
                if(i==0)
                    t[i][j] = 0;
                if(j==0)
                    t[i][j] = 1;
            }
        for(int i =1; i<n+1; i++)
            for(int j =0; j<sum+1; j++)
            {
                if(nums[i-1]<=j)
                    t[i][j] = (t[i-1][j-nums[i-1]] + t[i-1][j])%mod;
                else if(nums[i-1]>j)
                    t[i][j] = (t[i-1][j])%mod;
            }
        
        return (t[n][sum])%mod;
    }
	int perfectSum(int nums[], int n, int sum)
	{
        vector<vector<int>> t(n+2,vector<int>(sum+2,-1));
        return helper(nums,sum,n,t);
	}
	  
};
