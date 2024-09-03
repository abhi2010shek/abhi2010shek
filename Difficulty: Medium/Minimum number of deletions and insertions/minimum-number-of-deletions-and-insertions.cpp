//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int LCS(int i, int j,int &n, int &m, string &str1, string &str2, vector<vector<int>> &dp) {
	    if(i==n || j==m){
	       return 0; 
	    }
	    
	    if(dp[i][j]!=-1) return dp[i][j];
	    if(str1[i]==str2[j]) {
	        return dp[i][j] = 1 + LCS(i+1,j+1,n,m, str1,str2,dp);
	    }
	    else {
	        return dp[i][j] = max(LCS(i+1,j,n,m,str1,str2,dp),LCS(i,j+1,n,m,str1,str2,dp));
	    }
	}
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n=str1.size(), m= str2.size();
	    vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
	    int v = LCS(0,0,n,m,str1,str2,dp);
	    return (n+m-(2*v));
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends