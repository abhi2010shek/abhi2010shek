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
            int ans = sln.kthMissing(a, k);

            System.out.println(ans);
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


class Solution {
    public int kthMissing(int[] arr, int k) {
        // code here
        if(k<arr[0]){
            return k;
        }
        
        int l=0;
        int h=arr.length-1;
        
        int m=0;
        while(l<=h){
            m=(l+h)>>1;
            if(f(arr,m)>k){
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        return arr[h]+(k-(arr[h]-h))+1;
        
    }
    
    public static int f(int a[],int m){
        return a[m]-m;
    }
}