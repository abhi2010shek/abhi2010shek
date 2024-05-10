//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    void solve(vector<int>& arr, int n, int k, vector<vector<int>>& ans, vector<int> &res, int i){
        if(k==0){
            ans.push_back(res);
            return;
        }
        
        if((i>=n) or (k<0)) return;
        
        res.push_back(arr[i]);
        solve(arr,n,k-arr[i],ans,res,i+1);
        res.pop_back();
        
        while(i+1 < n and arr[i]==arr[i+1]){
            i++;
        }
        
        solve(arr,n,k,ans,res,i+1);
        
    }

    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        //code here
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        vector<int> res;
        
        solve(arr,n,k,ans,res,0);
        

        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends