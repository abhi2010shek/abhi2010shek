class Solution {
public:
    long long countSubarrays(vector<int>& arr, int k) {
        long long n=arr.size();
        long long m=*max_element(arr.begin(), arr.end());
        long long i=0,j=0, cnt=0, ans=0;
        while(j<n){
           if(arr[j]==m){
               cnt++;
           }
           if(cnt >=k){
               while(cnt>=k){
               ans+=n-j;
               if(arr[i]==m){
                    cnt--;
               }
               i++;
               }
               }
            j++;
        }
        return ans;
    }
};