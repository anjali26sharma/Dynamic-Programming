https://practice.geeksforgeeks.org/problems/shortest-common-supersequence0322/1

class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    
    int LCS(string X, string Y, int m, int n , vector<vector<int>> &t)
    {
        for(int i =0; i< m+1; i++)
        for(int j =0; j< n+1 ; j++)
        if(i==0 || j ==0)
        t[i][j] =0;
         for(int i =1; i< m+1; i++)
        for(int j =1; j< n+1 ; j++)
        {
            if(X[i-1] == Y[j-1])
            t[i][j] = 1+t[i-1][j-1];
            else
            t[i][j] = max(t[i-1][j],t[i][j-1]);
        }
        return t[m][n];
    }
   
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        vector<vector<int>> t(m+2,vector<int>(n+2,-1));
        int ans = LCS( X, Y, m, n, t);
        return m + n - ans;
    }
};
