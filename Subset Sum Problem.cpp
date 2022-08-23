class Solution{   
public:
    bool helper(vector<int>arr, int sum, int n, vector<vector<bool>> &t)
    {
        for(int i =0; i<n+1; i++)
        for(int j = 0; j<sum+1; j++)
        {
            if(i == 0 )
            t[i][j] = false;
            if(j == 0)
            t[i][j] = true;
            for(int i =1; i< n+1; i++)
            for(int j =1; j< sum+1; j++)
            {
                if(arr[i-1] <=j)
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
                else if(arr[i-1]>j)
                t[i][j] = t[i-1][j];
            }
            return t[n][sum];
        }
        // This is memoization appraoch but there is time limit exceed error
        /*  if(n==0 && sum == 0)
        return true;
        else if(sum ==0)
        return true;
        else if(n == 0 && sum != 0)
        return false;
        if(t[n][sum] != NULL)
        return t[n][sum];
        if(arr[n-1]<=sum)
        {
            return t[n][sum] = helper(arr, sum - arr[n-1], n-1, t) || helper(arr,sum,n-1,t);
        }
        else return t[n][sum] = helper(arr,sum,n-1,t);
        */
        
    }
    bool isSubsetSum(vector<int>arr, int sum){
       int n = arr.size();
       vector<vector<bool>> t(n+2,vector<bool>(sum+2, NULL));
       return helper(arr,sum,n,t);
    }
};
