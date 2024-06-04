//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
        int c=0;
        int add=1;
        int n=s.size();
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='0' && add==1 && c==1)
            {
                s[i]='0';
                add=0;
                c=1;
            }
            else if(s[i]=='0' && add==1 && c==0)
            {
                s[i]='1';
                add=0;
                c=0;
            }
            else if(s[i]=='0' && add==0 && c==1)
            {
                s[i]='1';
                add=0;
                c=0;
            }
            else if(s[i]=='0' && add==0 && c==0)
            {
                s[i]='0';
                add=0;
                c=0;
            }
            else if(s[i]=='1' && add==1 && c==1)
            {
                s[i]='1';
                add=0;
                c=1;
            }
            else if(s[i]=='1' && add==1 && c==0)
            {
                s[i]='0';
                add=0;
                c=1;
            }
            else if(s[i]=='1' && add==0 && c==1)
            {
                s[i]='0';
                add=0;
                c=1;
            }
            else if(s[i]=='1' && add==0 && c==0)
            {
                s[i]='1';
                add=0;
                c=0;
            }
        }
        if(c==1)
            s='1'+s;
        int i=0;
        while(s[i]=='0')
            i++;
        s=s.substr(i,n-i+1);
        return s;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends