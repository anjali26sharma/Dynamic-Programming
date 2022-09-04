https://leetcode.com/problems/scramble-string/

class Solution {
public:
    unordered_map<string,bool> m;
    bool solve(string a , string b)
    {   
        string s = a+ " " + b;
        
        if(a==b)                                                            // better than a.compare(b)==0
            return m[s] = true;
        if(a.length()<=1)
            return m[s] = false;
        
        if(m.find(s) != m.end())
            return m[s];
        int n = a.length();
        bool flag = false;
        for(int i =1; i<= n-1; i++)
        {
            bool condn1 = solve(a.substr(0,i),b.substr(n-i,i)) && solve(a.substr(i,n-i),b.substr(0,n-i));
            bool condn2 = solve(a.substr(0,i),b.substr(0,i))  && solve(a.substr(i,n-i),b.substr(i,n-i));
            if(condn1 || condn2)
            {
                flag = true;
            }
        }
       
        return m[s]= flag;
    }
    
    bool isScramble(string a, string b) {
        if(a.length()!=b.length())
            return false;
        vector<int> v(26,0);
        for(int i = 0; i<a.size();i++)                         //this is to check if all the alphabets in two string are equal or not
        {
            v[a[i]-'a']++;
            v[b[i]-'a']--;
        }
        for(int i = 0; i< 26 ;i++)
        {
            if(v[i] !=0)
                return false;
        }
        
        return solve( a ,  b);
        
    }
};
