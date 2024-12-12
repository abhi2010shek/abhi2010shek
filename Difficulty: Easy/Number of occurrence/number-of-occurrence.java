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
            int ans = sln.countFreq(a, k);

            System.out.println(ans);
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


class Solution {
    int firstoccur(int[] arr, int target){
        int first = -1;
        int i = 0;
        int j = arr.length-1;
        while(i<=j){
            int mid = i+(j-i)/2;
            if(arr[mid] == target){
                first = mid;
                j = mid-1;
            }
            else if(arr[mid] < target){
                i = mid+1;
            }
            else{
                j = mid-1;
            }
        }
        return first;
        
    }
    
    int lastoccur(int[] arr, int target){
        int last = -1;
        int i = 0;
        int j = arr.length-1;
        while(i<=j){
            int mid = i+(j-i)/2;
            if(arr[mid] == target){
                last = mid;
                i = mid+1;
            }
            else if(arr[mid] < target){
                i = mid+1;
            }
            else{
                j = mid-1;
            }
        }
        return last;
        
    }
    
    int countFreq(int[] arr, int target) {
        int lower = firstoccur(arr, target);
        int upper = lastoccur(arr, target);
        
        if(lower == -1 || upper == -1){
            return 0;
        }
        return upper-lower+1;
        
    }
}
