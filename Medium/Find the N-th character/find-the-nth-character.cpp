//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        //code here
        n++;
        string f;
        long int it = 0, p, i, j, len = 0;
        while (len < n) {
            it++;
            len = it * pow(2, r);
        }
        p = pow(2, r);
        n--;
        n = n % p;
        if (it == 0)
            it++;
        f += s[it - 1];
        for (i = 0; i < r; i++) {
            s.clear();
            
            for (j = 0; j < f.length(); j++) {
                if (f[j] == '1')
                    s += "10";
                else
                    s += "01";
            }
            
            f.clear();
            f += s;
        }
        return f[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends