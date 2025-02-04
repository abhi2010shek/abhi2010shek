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
            int ans = sln.aggressiveCows(a, k);

            System.out.println(ans);
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


// User function Template for Java
class Solution {
    public static int aggressiveCows(int[] stalls, int k) {
        Arrays.sort(stalls);
        int res = 0; 
        int lo = 1;
        int hi = stalls[stalls.length - 1] - stalls[0]; 

        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(check(stalls, k, mid)) {
                res = mid;
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        
        return res;
    }
    static boolean check(int[] stalls, int k, int dist) {
        
        int cnt = 1;  
        int prev = stalls[0]; 
        for (int i = 1; i < stalls.length; i++) {
    
            if (stalls[i] - prev >= dist) {
                prev = stalls[i]; 
                cnt++; 
            }
        }

        return (cnt >= k);
    }
}