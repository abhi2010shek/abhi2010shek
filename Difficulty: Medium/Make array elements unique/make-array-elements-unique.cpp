//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minIncrements(vector<int> arr) {
        // Code here
        sort(arr.begin(),arr.end());
        int currNum=arr[0];
        int ans=0;
        
        for(int i=1;i<arr.size();i++)
        {
            if(currNum >= arr[i])
            {
                ans+=abs(currNum + 1 - arr[i]);
                arr[i]=currNum+1;
            }
                currNum=arr[i];
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int ans = ob.minIncrements(a);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends