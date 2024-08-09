//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    static const int m = 1000000007;
    int Maximize(vector<int> &a) {
        sort(a.begin(), a.end());
        int n = a.size();
        long long sum = 0;
        for(long int i=0; i<n; i++){
            sum = sum + ((i%m)*(a[i]%m))%m;
            sum = sum%m;
        }
        return sum%m;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        //  cin.ignore();
        int n = arr.size();
        Solution ob;
        cout << ob.Maximize(arr) << endl;
    }
}
// } Driver Code Ends