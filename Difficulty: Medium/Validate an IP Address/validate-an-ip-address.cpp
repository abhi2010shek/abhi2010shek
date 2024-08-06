//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int isValid(string s) {
        // code here
        int cnt = 0;
       
       vector<string>p;
       
       string curr="";
       
       for(auto c:s)
       {
           if(c=='.')
           {
               if(curr.empty()) return 0;
               p.push_back(curr);
               curr = "";
               cnt++;
           }
           else
           curr+=c;
       }
       
       if(!curr.empty())
       p.push_back(curr);
       
       if(cnt!=3) return 0;
       
       for(auto x:p)
       {
        //   cout<<x<<endl;
           if(x[0]=='0' && x.length()>1) return 0;
           for(auto c:x)
           {
               if(!isdigit(c)) return 0;
           }
           
           int val = stoi(x);
           if(val<0 || val>255) return 0;
       }
       
       return 1;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends