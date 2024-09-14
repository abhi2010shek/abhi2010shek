//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &v) {
        // code here
        vector<int>a,b;
        for(auto i:v){
            if(i<0)a.push_back(i);
            else b.push_back(i);
        }
        for(int i=0,j=0;i<v.size();i+=2,j++){
            if(b.size()>j)v[i]=b[j];
            else {
               while(a.size()>j){
                //   if(i>=v.size())break;
                   v[i]=a[j];
                   j++;
                   i++;
               }
               break;
            }
            if(a.size()>j)v[i+1]=a[j];
            else {
                j++;
               while(b.size()>j){
                    // if(i>=v.size())break;
                   v[i+1]=b[j];
                   i++;
                   j++;
               }
               break;
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends