//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t > 0) {
            String inputLine[] = br.readLine().trim().split(" ");
            int n = inputLine.length;
            int arr[] = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(inputLine[i]);
            }
            Solution ob = new Solution();
            int[] ans = new int[n];
            ans = ob.productExceptSelf(arr);

            for (int i = 0; i < n; i++) {
                System.out.print(ans[i] + " ");
            }
            System.out.println();
            System.out.println("~");
            t--;
        }
    }
}

// } Driver Code Ends


// User function Template for Java
class Solution {
    public static int[] productExceptSelf(int arr[]) {
        // code here
        int n = arr.length;
        int zeroes = 0, sum = 1, idx = -1;
        int res[] = new int[n];
        for(int i=0; i<n; i++){
            if(arr[i] == 0){
                zeroes++;
                idx = i;
            } else {
                sum *= arr[i];
            }
        }
        Arrays.fill(res, 0);
        if(zeroes == 0){
            for(int i=0; i<n; i++){
                res[i] = sum/arr[i];
            }
        }
        else if(zeroes == 1){
            res[idx] = sum;
        }
        return res;
    }
}
