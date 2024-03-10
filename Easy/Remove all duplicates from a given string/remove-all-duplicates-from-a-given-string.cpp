//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	    // code here
	    int freq[58]={0};
	    for(int i=0;i<str.length();i++)
	        freq[str[i]-'A']++;
	    
	    string ans="";
	    for(int i=0;i<str.length();i++)
	    {
	        if(freq[str[i]-'A']>0)
	        {
	            ans+=str[i];
	            freq[str[i]-'A'] = -freq[str[i]-'A'];
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends