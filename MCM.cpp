1//https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

class Solution{
public:
    int solve(int arr[], int i , int j, vector<vector<int>> &t)
    {
        if(i>=j)
        return 0;
        if(t[i][j] != -1)
        return t[i][j];
        int mn = INT_MAX;
        for(int k =i; k<= j-1; k++)
        {
            int temp = solve(arr, i , k,t) + solve(arr,k+1, j,t) + arr[i-1]*arr[k]*arr[j];
            mn = min(mn , temp);
        }
        return t[i][j]= mn;
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> t(N+1,vector<int>(N+1,-1));
       int i =1 , j = N-1;
       return solve(arr,i,j,t);
    }
};
