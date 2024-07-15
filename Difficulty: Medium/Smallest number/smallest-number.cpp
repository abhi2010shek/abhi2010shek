//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code here
        if (d == 1 && s >9){
            return "-1";
        }

        string str;
        vector<int> temp(d, 0);

        
        s -= 1;

        for (int i = d - 1; i > 0; i--) {
            if (s >= 9) {
                temp[i] = 9;
                s -= 9;
            } else {
                temp[i] = s;
                s = 0;
            }
        }

        temp[0]=s+1;
        for (int i = 0; i < d; i++) {
            str += to_string(temp[i]);
        }
         if (temp[0] > 9) {
            return "-1";
        }

        return str;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends