//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int merge(vector<int> &a, int low, int mid, int high){
        vector<int> temp;
        int left=low,right=mid+1, c=0;
        
        while(left<=mid && right<=high){
            if(a[left]<=a[right])
            {
                temp.push_back(a[left]);
                left++;
            }
            else{
                c+=(mid-left+1);
                temp.push_back(a[right]);
                right++;
            }
        }
        
        while(left<=mid){
            temp.push_back(a[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(a[right]);
            right++;
        }
        
        for(int i=low; i<=high; i++)
        a[i]=temp[i-low];
        
        return c;
    }
    int mergesort(vector<int> &a, int low, int high){
        int c=0;
        
        if(low>=high)
        return c;
        
        int mid=(low+high)/2;
        c+=mergesort(a, low, mid);
        c+=mergesort(a, mid+1, high);
        c+=merge(a, low, mid, high);
        
        return c;
    }
    int countPairs(int arr[] , int n ) 
    {
        // Your code goes here   
        vector<int> a;
        for(int i=0; i<n; i++)
        a.push_back(i*arr[i]);
        
        return mergesort(a, 0, n-1);
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	Solution ob;
    	cout<<ob.countPairs(a, n)<<endl;
    }
}
// } Driver Code Ends