https://practice.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1

class Solution{
public:

    pair<string,int> helper(int arr[], int i , int j, vector<vector<pair<string,int>>> &t)
    {
        if(i>=j)
        {
            string st = "";
            st = 'A' + i-1;
            return {st,0};
        }
        if(t[i][j].second != -1)
        return t[i][j];
        
        int mn = INT_MAX;
        string sr= "";
        for(int k = i; k<=j-1; k++)
        {
            auto pr1 = helper(arr,i,k,t);
            auto pr2 = helper(arr,k+1,j,t);
            int temp = pr1.second + pr2.second + arr[i-1]*arr[j]*arr[k];
            string s = "";
            s = "(" + pr1.first + pr2.first + ")";
            if(mn>temp)
            {
                mn = temp;
                sr = s;
            }
             
        }
        return t[i][j]= {sr,mn};
    }
    string matrixChainOrder(int arr[], int n){
        vector<vector<pair<string,int>>> t(n+1,vector<pair<string,int>>(n+1,{"",-1}));
        auto ans = helper(arr,1,n-1,t);
        return ans.first;
        
    }
};
