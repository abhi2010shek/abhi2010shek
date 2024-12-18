//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());

        while (tc-- > 0) {

            String[] str = br.readLine().trim().split(" ");
            int[] a = new int[str.length];
            for (int i = 0; i < str.length; i++) {
                a[i] = Integer.parseInt(str[i]);
            }
            String[] nk = br.readLine().trim().split(" ");
            int k = Integer.parseInt(nk[0]);
            Solution sln = new Solution();
            int ans = sln.findPages(a, k);

            System.out.println(ans);
            System.out.println("~");
        }
    }
}
// } Driver Code Ends



//Back-end complete function Template for Java

class Solution {
    public static int findPages(int[] arr, int k) {
        if(k > arr.length)
            return -1;
        
        int mi = arr[0], sum = arr[0];
        for(int i=0;i<arr.length;i++){
            sum += arr[i];
            mi = Math.min(mi, arr[i]);
        }
        int l = mi, r = sum;
        
        int res = -1;
        
        while(l <= r){
            int mid = l + (r-l)/2;
            if(isPossible(mid,k, arr)){
                res = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return res;
    }
    static boolean isPossible(int mid, int k, int[] arr){
        
        int students = 1, pages = 0;
        for(int i=0;i<arr.length;i++){
            if(arr[i] > mid)return false;
            if(pages + arr[i] <= mid){
                pages += arr[i];
            }
            else {
                students++;
                pages = arr[i];
            }
        }
        return students <= k;
    }
}