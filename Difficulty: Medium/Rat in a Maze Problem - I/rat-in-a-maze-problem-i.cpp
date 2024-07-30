//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    
    void solve(int i, int j, int n, string s, vector<string> & ans, vector<vector<int>> & mat, vector<vector<int>> visited)
    {
        if(i<0 || j<0 || i>=n || j>=n || visited[i][j]) return;
        visited[i][j]=1;
        if(mat[i][j]==0) return;
        if(i==n-1 and j==n-1)
        {
            ans.push_back(s);
            return;
        }
        
        solve(i, j+1, n, s+"R", ans, mat, visited);
        solve(i, j-1, n, s+"L", ans, mat, visited);
        solve(i+1, j, n, s+"D", ans, mat, visited);
        solve(i-1, j, n, s+"U", ans, mat, visited);
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        
        vector<string> ans;
        string s="";
        vector<vector<int>> visited(mat.size(), vector<int> (mat[0].size(), 0));
        solve(0,0,mat.size(), s,ans,mat, visited);
        if(ans.size()==0) ans.push_back("-1");
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends