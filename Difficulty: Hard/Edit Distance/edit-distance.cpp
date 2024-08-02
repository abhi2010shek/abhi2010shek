//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int dp[101][101];
  public:int isans(string s,int n, string t,int m){
      
      if(n==0)return m;
      if(m==0)return n;
      if(dp[n][m]!=-1)return dp[n][m];
      if(s[n-1]==t[m-1]) return dp[n][m]=isans(s,n-1,t,m-1);
      return dp[n][m]=1+min(min(isans(s,n-1,t,m),isans(s,n,t,m-1)),isans(s,n-1,t,m-1));
      
      
  }
  
    int editDistance(string s, string t) {
        // Code here
        
        memset(dp,-1,sizeof(dp));
        return isans(s,s.size(),t,t.size());
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends