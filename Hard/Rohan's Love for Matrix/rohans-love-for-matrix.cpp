//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
int dp[1000006];
int mod=1e9+7;
int fn(int n){
    if(n==1)return 1;
    if(n==2)return 1;
    if(dp[n]!=0)return dp[n];
    int ans=fn(n-1)%mod+fn(n-2)%mod;
    return dp[n]=ans%mod;
}
class Solution {
  public:
    int firstElement(int n) {
       return fn(n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends