//https://leetcode.com/problems/super-egg-drop/


// Method 1 : DP + Recursion
// TC : O(k(n*n)) [TLE]
// SC : O(k*n)

int solve(int k,int n,vector<vector<int>>&dp){
    // base case
    if(n==0 || n==1 || k==1){
        return n;
    }
    
    int &ans = dp[k][n];
    if(ans!=-1){
        return ans;
    }
    
    ans = INT_MAX;
    for(int i=1;i<=n;i++){
        int res = 1 + max(solve(k-1,i-1,dp),solve(k,n-i,dp));
        ans = min(res,ans);
    }
    return ans;
}

int superEggDrop(int k, int n) {
    vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
    return solve(k,n,dp);
}



// Method 2 : DP + Recursion + Binary Search
// TC : O(k*log(n))
// SC : O(k*n)
int solve(int k,int n,vector<vector<int>>&dp){
    // base case
    if(n==0 || n==1 || k==1){
        return n;
    }
    
    int &ans = dp[k][n];
    if(ans!=-1){
        return ans;
    }
    
    ans = INT_MAX;
    int low = 1;
    int high = n;
    
    
    while(low<=high){
        int mid = low + (high-low)/2;
        
        int a = solve(k-1,mid-1,dp);        // not break
        int b = solve(k,n-mid,dp);          // break
        
        
        int res = 1 + max(a,b);
        if(a<=b){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
        
        ans = min(res,ans);
    }
    return ans;
}

int superEggDrop(int k, int n) {
    vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
    return solve(k,n,dp);
}
