//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        unordered_map<char,int> sd;
        for(auto &it:s){
            sd[it]++;
        }
        priority_queue<int> pq;
        for(auto &it:sd){
            pq.push(it.second);
        }
        while(!pq.empty() and k>0){
            int d = pq.top();
            d--;
            pq.pop();
            pq.push(d);
            k--;
        }
        int ans = 0;
        while(!pq.empty()){
            ans+=(pq.top()*pq.top());
            pq.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends