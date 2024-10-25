//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    vector<int> alternateSort(vector<int>& arr) {
        // Your code goes here
        sort(begin(arr), end(arr));
        vector<int>ans;
        int leftIdx = 0;
        int rightIdx = arr.size()-1;
        bool alternate = true;
        while(leftIdx<=rightIdx){
             if(alternate==true){
                 ans.push_back(arr[rightIdx]);
                 rightIdx--;
                 alternate = false;
             } 
             else{
                 ans.push_back(arr[leftIdx]);
                 leftIdx++;
                 alternate = true;
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
        vector<int> ans = obj.alternateSort(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends