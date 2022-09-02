https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1

class Solution{
public:


	unordered_map<string,int> mp;
    int solve(string &s, int i, int j, char isTrue)
    {
        if(i>j)
            return 0;
        if(i==j)
            {
                if(isTrue == 'T')
                return s[i]=='T';
                else return s[i]=='F';
            }
        string temp=to_string(i)+" "+to_string(j)+" "+to_string(isTrue);
        if(mp.find(temp)!=mp.end())
            return mp[temp];
        int ans=0;
        for(int k=i+1;k<j;k+=2)
        {
            int lt=solve(s,i,k-1,'T');
            int lf=solve(s,i,k-1,'F');
            int rt=solve(s,k+1,j,'T');
            int rf=solve(s,k+1,j,'F');
            if(s[k]=='&')
                ans+=(isTrue=='T')?(lt*rt):(lt*rf)+(lf*rt)+(lf*rf);
            else if(s[k]=='|')
                ans+=(isTrue=='T')?(lt*rf)+(lf*rt)+(lt*rt):(lf*rf);
            else
                ans+=(isTrue=='T')?(lt*rf)+(lf*rt):(lt*rt)+(lf*rf);
        }
        return mp[temp]=(ans%1003);
    }
    int countWays(int N, string S){
        return solve(S,0,N-1,'T');
    }
    
};
