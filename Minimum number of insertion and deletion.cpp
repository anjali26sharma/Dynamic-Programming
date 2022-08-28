https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1

class Solution{
		
  public:
	
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
    
	int minOperations(string str1, string str2) 
	{ 
	   int n = str1.length();
	   int m = str2.length();
	   vector<vector<int>> t(n+1,vector<int>(m+1,-1));
	   int ans = n+m - 2*LCS(str1,str2,n,m,t);
	   return ans;
	    
	} 
};
