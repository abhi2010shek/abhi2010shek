//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long mod = 1e9+7;
    
    long long ad_mod(long long a,long long b){
        return ((a%mod)+(b%mod))%mod;
    }
    
    long long mul_mod(long long a,long long b){
        return ((a%mod)*(b%mod))%mod;
    }
 

    long long sumSubstrings(string s){
        long long cur = 0;
        long long pre = s[0]-'0';
        long long sum = pre;
        for(long long i=1;i<s.size();i++){
            cur = ad_mod( mul_mod(pre , 10) , mul_mod(1LL*(i+1),1LL*(s[i]-'0')));
            sum = ad_mod(sum,cur);
            pre = cur;
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends