//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int>& nums1, vector<int>& nums2) {
         int n = nums1.size() , m = nums2.size();
        if(n>m)return kthElement( k, nums2, nums1);
       
        int low =  max(k-m,0), high = min(k , n);
        int left = k;
        while(low<=high){
            int mid1 = low+(high-low)/2;
            int mid2 = left - mid1;
            int l1=INT_MIN , l2 = INT_MIN , r1=INT_MAX,r2=INT_MAX;
 
            if(mid1>=1)l1 = nums1[mid1-1];
            if(mid2>=1)l2= nums2[mid2-1];
            if(mid1<n)r1 = nums1[mid1];
            if(mid2<m)r2 = nums2[mid2];
            
            if(l1<=r2 && l2<=r1){
                return max(l1,l2);
            }
            if(l1>r2){
                high = mid1-1;
            }
            else{
                low = mid1+1;
            }   
        }
        return -1;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends