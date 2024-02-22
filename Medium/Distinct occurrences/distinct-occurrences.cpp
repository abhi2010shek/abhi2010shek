//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

#define mod 1000000007
class Solution
{
    public:
      int solve(int i, int j, int n, int m, string s, string t, vector<vector<int>> &dp) 
    {
        if(j == m)
            return 1;
            
        if(i == n)
            return 0;
            
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == t[j]) 
        {
            int notTake = solve(i + 1, j, n, m, s, t, dp);
            int take = solve(i + 1, j + 1, n, m, s, t, dp);
            dp[i][j] = (notTake + take) % mod;
        } else 
        {
            dp[i][j] = solve(i + 1, j, n, m, s, t, dp) % mod;
        }
        
        return dp[i][j] % mod;
    }        
    int subsequenceCount(string s, string t)
    {
      //Your code here
       int n = s.size(), m = t.size();
        vector<int> next(m + 1), curr(m + 1);
        next[m] = 1;
            
        for(int i = n - 1; i >= 0; i--) 
        {
            curr[m] = 1;
            for(int j = m - 1; j >= 0; j--) 
            {
                if(s[i] == t[j]) 
                {
                    int notTake = next[j];
                    int take = next[j + 1];
                    curr[j] = (notTake + take) % mod;
                } 
                else 
                {
                    curr[j] = next[j] % mod;
                }
            }
            
            next = curr;
        }
        
        return next[0] % mod;
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends