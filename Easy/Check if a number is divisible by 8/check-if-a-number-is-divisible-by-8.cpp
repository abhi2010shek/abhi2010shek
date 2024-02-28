//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
        int n=s.size();
        if(n<3)
        {
            int num=0;
            for(int i=0;i<n;i++)
            {
                num=num*10+(s[i]-'0');
            }
            if(num%8==0)
            {
                return 1;
            }
        }
        else
        {
            int num=0;
            for(int i=n-3;i<=n-1;i++)
            {
                num=num*10+(s[i]-'0');
            }
            if(num%8==0)
            {
                return 1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends