//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int padovanSequence(int n)
    {
       //code here
       int a =1 ;
       int b =1 ;
       int c =1 ;
       for (int i=3;i<=n;i++) {
           int t = c%(1000000000+7) ;
           c = (a+b)%(1000000000+7) ;
           a = b%(1000000000+7) ;
           b = t%(1000000000+7) ;
       }
       return c%(1000000000+7) ;
    }
    
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout<<ob.padovanSequence(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends