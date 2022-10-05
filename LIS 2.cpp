//https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    
int LCS(int n, int m, vector<int> arr1, vector<int> arr2, vector<vector<int>> &t )
{
    
    for(int i =0 ; i< n+1; i++)
        for(int j =0 ; j< m+1; j++)
        {
            if(i==0 || j==0)
                t[i][j]=0;
        }
    for(int i = 1; i<n+1; i++)
        for(int j = 1 ; j<m+1; j++)
        {
            if(arr1[i-1]==arr2[j-1])
                t[i][j] = 1+t[i-1][j-1];
            else
                t[i][j] = max(t[i-1][j],t[i][j-1]);
        }
    return t[n][m];
}
    
        int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> v;
        set<int> s;                                   //stores unique number in sorted manner
        for(int i =0 ; i< nums.size(); i++)
            s.insert(nums[i]);
        
        for(auto i = s.begin() ; i !=s.end(); i++)
            v.push_back(*i);
        int m = v.size();
        vector<vector<int>> t(n+1,vector<int>(m+1,-1));
       
        return LCS(n,m,nums,v,t);
    }
};
