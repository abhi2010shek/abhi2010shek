//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  int mod = 1e9 + 7;
  public:
    int numberOfConsecutiveOnes(int n) {
        // code here
        vector<long> count1({1,0,1,0}), count2(4);
        for(int i = 1; i < n; i++) {
            count2[0] = (count1[0] + count1[2]) % mod;
            count2[1] = (count1[1] + count1[3]) % mod;
            count2[2] = count1[0];
            count2[3] = (count1[1] + count1[2] + count1[3]) % mod;
            count1 = count2;
        } 
        return (count1[1] + count1[3]) % mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}

// } Driver Code Ends