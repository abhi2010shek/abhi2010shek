//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	    // code here 
	    int arr[26] = {0};
	    for(char i : s) arr[i-'a']++;
	    int mx = *max_element(arr,arr+26),val = 0,cnt = 0,cnt1 = 0;
	    for(int i=0;i<26;i++){
	        if(arr[i] == mx) cnt++;
	        else if(arr[i]){
	            cnt1++;
	            if(val == 0) val = arr[i];
	            else{
	                if(arr[i] != val) return false;
	            }
	        }
	    }
	    if((cnt > 1 && cnt1 > 1) || (cnt == 1 && cnt1 >= 1 && mx - val > 1) || (cnt1 == 1 && cnt > 1 && val != 1)) return false;
	    return true;
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends