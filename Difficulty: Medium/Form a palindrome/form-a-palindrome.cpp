//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int solve(int i,int j,string str, vector<vector<int>>&dp){
        if(i>=j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(str[i]==str[j]){
            return dp[i][j]=solve(i+1,j-1,str,dp);
        }
        else{
            return dp[i][j]=1+min(solve(i+1,j,str,dp),solve(i,j-1,str,dp));
        }
    }
    int countMin(string str){
    //complete the function here
    vector<vector<int>>dp(str.size(),vector<int>(str.size(),-1));
      return solve(0,str.size()-1,str,dp);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends