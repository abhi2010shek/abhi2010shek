//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findExtra(int n, int arr1[], int arr2[]) {
        // add code here.
        int low = 0, high = n-1;
            
            while(low < high){
                int mid = (low+high)>>1;
                if(arr1[mid] == arr2[mid]){
                    low = mid+1;
                }
                else if(arr1[mid] != arr2[mid]){
                    high = mid;
                }
            }
            
            if(arr1[n-1] != arr2[n-2] ){
                return n-1;
            }
            
            return low;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr1[n], arr2[n - 1];
        for (int i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> arr2[i];
        }
        Solution obj;
        cout << obj.findExtra(n, arr1, arr2) << endl;
    }
}
// } Driver Code Ends