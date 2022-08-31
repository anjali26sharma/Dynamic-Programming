//https://leetcode.com/problems/palindrome-partitioning-ii/

class Solution {
public:
    bool isPalindrome(string &s, int i , int j)
    {
        int start = i, end = j;
        while(i<=j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
    
    int helper(string &str, int i , int j, vector<vector<int>> &t)
    {
        if(i==j)
            return t[i][j] = 0;
        if(t[i][j] != -1)
            return t[i][j];
        if(isPalindrome(str,i,j) == true)
            return t[i][j] = 0;
        int mn = INT_MAX;
        for(int k =i; k<=j-1; k++)
        {
            if(isPalindrome(str,i,k))
            {
              int temp =  helper(str, k+1, j, t) + 1;
              if(temp < mn)
              mn = temp;
            }
            
        }
        return t[i][j] = mn;
    }
    
    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> t(n+1,vector<int>(n+1,-1));
        return helper(s,0,n-1,t);
    }
};

