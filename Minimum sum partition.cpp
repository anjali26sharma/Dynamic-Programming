//https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1

class Solution{

   public:
   
   int helper(int arr[], int n,int range, vector<vector<bool>> &t)
   {
       for(int i =0; i<n+1; i++)
       for(int j =0; j<range+1; j++)
       {
           if(i==0)
       t[i][j]=false;
       if(j==0)
       t[i][j]=true;
       }
       for(int i = 1; i<n+1; i++)
       for(int j =0; j<range+1; j++)
       {
           if(arr[i-1]<=j)
           t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
           else 
           t[i][j] = t[i-1][j];
       }
       
       for(int i = range/2; i>=0 ; i--)
       {if(t[n][i]== true)
       return i;
       }
       return 0;
   }
 
	int minDifference(int arr[], int n)  { 
	    int range = 0;
	    for(int i =0; i<n; i++)
	    range += arr[i];
	    vector<vector<bool>> t(n+2,vector<bool>(range+2,NULL));
	    int ans = helper(arr,n,range,t);
	    return range - (2*ans);
	} 
};
