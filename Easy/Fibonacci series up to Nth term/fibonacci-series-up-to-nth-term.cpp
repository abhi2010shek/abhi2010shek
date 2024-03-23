//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Series(int n) {
        // Code here
        int a=0,b=1,i=1;
        vector<int>v;
        v.push_back(a);
        v.push_back(b);
         for (int i=0; i<n-1; i++){
            int temp = (a+b)%1000000007;
            v.push_back(temp);
            a = b;
            b = temp;
        }
        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends