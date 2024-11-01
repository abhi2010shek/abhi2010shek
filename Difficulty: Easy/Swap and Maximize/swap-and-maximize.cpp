//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// long long int maxSum(int arr[], int n);

// } Driver Code Ends
class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end());
        vector<int>ans;
        long long sum=0;
        
        for(int i=0;i<arr.size()/2;i++){
            if(i!=arr.size()-1-i){
            ans.push_back(arr[i]);
            ans.push_back(arr[arr.size()-1-i]);
            }
            else
            ans.push_back(arr[i]);
        }
        for(int i=0;i<ans.size()-1;i++){
            sum+=(abs(ans[i]-ans[i+1]));
        }
        return sum+abs(ans.back()-ans[0]);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends