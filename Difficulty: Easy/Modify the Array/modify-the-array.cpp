//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        // Complete the function
        int i;
        int n=arr.size();
        int j=n-1,k=0;
        vector<int> ans(n);
        for(i=0;i<n-1;i++)
        {
            if(arr[i]==arr[i+1])
            {
                arr[i]+=arr[i+1];
                arr[i+1]=0;
                i++;
            }
        }
        for(i=0;i<n;i++)
        {
            if(arr[i]!=0)
            {
                ans[k]=arr[i];
                k++;
            }
            else
            {
                ans[j]=arr[i];
                j--;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.modifyAndRearrangeArray(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends