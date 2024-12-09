//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
    
      vector<vector<int>> ans; 
       intervals.push_back(newInterval); 
       sort(intervals.begin(),intervals.end()); 
       int n = intervals.size(); 
       int i = 0; 
       int j ; 
       
       while(i<n){
           vector<int>ele = intervals[i]; 
           j = i+1; 
           while(j<n&& ele[1]>=intervals[j][0]){
               ele[1] = max(ele[1],intervals[j][1]); 
               j++; 
           }
           ans.push_back(ele); 
           i = j ; 
       }
         
         return ans; 
         
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        vector<int> newInterval(2);
        cin >> newInterval[0] >> newInterval[1];

        Solution obj;
        vector<vector<int>> ans = obj.insertInterval(intervals, newInterval);
        cout << "[";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[" << ans[i][0] << ',' << ans[i][1] << ']';
            if (i != (ans.size() - 1))
                cout << ",";
        }
        cout << "]" << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends