//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method*/
    int f(int i,int j,string pattern,string str,vector<vector<int>>&dp)
    {
        int n=pattern.size(),m=str.size();
        if(i>=n&&j>=m)
        return 1;
        if(i>=n)
        {
            return 0;
        }
        if(j>=m)
        {
            
            while(i<n&&pattern[i]=='*')
            {
                i++;
            }
            return i>=n;
        }
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(pattern[i]==str[j]||pattern[i]=='?')
        return dp[i][j]=f(i+1,j+1,pattern,str,dp);
        if(pattern[i]=='*')
        {
            return dp[i][j]=f(i,j+1,pattern,str,dp)||f(i+1,j,pattern,str,dp)||f(i+1,j+1,pattern,str,dp);
        }
        return dp[i][j]=0;
    }
    int wildCard(string pattern, string str) {
        // code here
        int n=pattern.size(),m=str.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        dp[n][m]=1;
        bool flag=true;
        for(int i=n-1;i>=0;i--)
        {
            if(pattern[i]!='*')
            flag=false;
            if(flag==true)
            dp[i][m]=1;
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(pattern[i]==str[j]||pattern[i]=='?')
                  dp[i][j]=dp[i+1][j+1];
                else if(pattern[i]=='*')
                dp[i][j]=dp[i+1][j]||dp[i+1][j+1]||dp[i][j+1];
            }
        }
        
        return dp[0][0];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends