https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

class Solution {
public:
    
    int LCS(string s1, string s2, int m , int n, vector<vector<int>> &t)
    {
        for(int i =0 ; i<m+1; i++)
            for(int j =0; j< n+1; j++)
                if(i==0 || j==0)
                    t[i][j]=0;
        for(int i = 1 ; i<m+1; i++)
            for(int j = 1; j< n+1; j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    t[i][j] = 1+t[i-1][j-1];
                }
                else
                    t[i][j] = max(t[i][j-1],t[i-1][j]);
            }
        return t[m][n];
    }
    
    int SCS(string s1, string s2, int m , int n)
    { 
        vector<vector<int>> t (m+1,vector<int>(n+1,-1));
        return m+n - LCS(s1,s2,m,n,t);
        
    }
    int minInsertions(string s) {
        string s2 = s;
        reverse(s2.begin(),s2.end());
        int m = s.length();
        int n = s2.length();
        return SCS(s,s2,m,n) - m;
    }
};
