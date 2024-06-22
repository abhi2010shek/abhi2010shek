//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isNum(char s){
        if(s>='0' && s<='9') return true;
        return false;
    }
    bool isCont(long long int val){
        while(val!=0){
            int rem= val%10;
            if(rem==9) return true;
            val/=10;
        }
        return false;
    }
    long long ExtractNumber(string s) {
       long long int ans=0;
       long long int val=0;
       for(int i=0;i<s.size();i++){
           if(isNum(s[i])) {
               val= val*10 + s[i]-'0';
           }else{
               val=0;
           }
           if(!isCont(val))
           ans= max(val,ans);
       }
        return ans==0 ?-1:ans;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends