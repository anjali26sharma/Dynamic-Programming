https://leetcode.com/problems/is-subsequence/

1. DP method 

class Solution {
public:
    int LCS(string text1, string text2, int n, int m , vector<vector<int>> &t)
    {
        for(int i =0; i<n+1; i++)
            for(int j =0; j<m+1; j++)
            {
                if(i==0 || j==0)
                    t[i][j]=0;
            }
        for(int i =1; i<n+1; i++)
            for(int j =1; j<m+1; j++)
            {
                if(text1[i-1]== text2[j-1])
                    t[i][j] = 1+t[i-1][j-1];
                else
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        return t[n][m];
    }
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int ans = LCS(s,t,n,m,dp);
        if(ans == n)
            return true;
        else return false;
    }
};


2. Two Pointer Method

class Solution {
public:
    
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        int i =0 , j =0;
        while(i<n && j<m)
        {
            if(s[i]==t[j])
            {
                i++; j++;
            }
            else
                j++;
        }
        if(i==n)
            return true;
        else return false;
    }
};
