//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   bool isPresent(int val, vector<int> arr, int n)
    {
        int l = 0;
        int h = n-1;
        
        while(l<=h)
        {
            int mid = (l+h)/2;
            if(arr[mid]==val)
                return true;
            else if(arr[mid] < val)
                l = mid+1;
            else
                h = mid-1;
        }
        
        return false;
    }
    
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        // Code here
        unordered_set<int> st;
        int n1 = arr1.size();
        int n2 = arr2.size();
        
        for(int i=0;i<n1;i++)
        {
            if(isPresent(arr1[i], arr2, n2))
                st.insert(arr1[i]);
        }
        
        int s1 = 0;
        int s2 = 0;
        
        vector<int> sar1;
        vector<int> sar2;
        
        for(int i=0;i<n1;i++)
        {
            int ele = arr1[i];
            if(st.find(ele)!=st.end())
            {
                sar1.push_back(s1);
                s1=0;
            }
            else
            {
                s1+=ele;
            }
        }
        sar1.push_back(s1);
        
        for(int i=0;i<n2;i++)
        {
            int ele = arr2[i];
            if(st.find(ele)!=st.end())
            {
                sar2.push_back(s2);
                s2=0;
            }
            else
            {
                s2+=ele;
            }
        }
        sar2.push_back(s2);
        
        int ans = 0;
        for(int i=0;i<=st.size();i++)
        {
            ans+=max(sar1[i],sar2[i]);
        }
        
        for(auto it : st)
        {
            ans+=it;
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
        vector<int> arr1;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }
        vector<int> arr2;
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            arr2.push_back(number2);
        }
        Solution ob;
        long long ans = ob.maxPathSum(arr1, arr2);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends