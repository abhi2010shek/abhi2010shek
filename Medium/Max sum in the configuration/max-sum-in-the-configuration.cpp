//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
  public:
    long long max_sum(int a[], int n) {
        // Your code here
        long long arraySum = 0, s = 0;
        
        for(long long int i = 0; i < n; i++){
            arraySum += a[i];
            s += i*a[i];
        }
        long long sum = s;
        for(long long int i = 1; i < n; i++){
            s += arraySum - n*(long long)a[n-i];
            sum = max(sum, s);
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends