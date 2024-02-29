//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	long long solve(int arr[], int &n){
        unordered_map<long long,long long>mp; //keeps track of set bits at a pos
        
        for(int i = 0; i<n; i++){
            long long num = arr[i];
            
            
            for(long long i = 0; i<31; i++){
                if(num&(1<<i)){
                    mp[i]++;
                }
            }
            
        }
        
        
        //just count the number who have 0 and 1 at a pos
        long long ans = 0;
        for(long long i = 0; i<31; i++){
            long long set_cnt = mp[i];
            
            long long off_bit = long(n) - set_cnt;
            ans += off_bit*set_cnt;
            
        }
        
        ans *= 2;
        
        
        return ans;
        
        
    }
	
	long long sumBitDifferences(int arr[], int n) {
	    // code here
	    long long ans = solve(arr, n);
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumBitDifferences(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends