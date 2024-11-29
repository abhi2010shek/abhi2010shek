//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            String a, b;
            a = sc.next();
            b = sc.next();
            Solution ob = new Solution();
            System.out.println(ob.addBinary(a, b));

            System.out.println("~");
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    public String addBinary(String s1, String s2) {
        // code here
        StringBuilder ans = new StringBuilder();
        int i = 0 , j = 0;
        int n = s1.length();
        int m = s2.length();
        while(i<n && s1.charAt(i)=='0')i++;
        while(j<m && s2.charAt(j)=='0')j++;
        s1 = s1.substring(i,s1.length());
        s2 = s2.substring(j,s2.length());
         n = s1.length();
         m = s2.length();
        if(n==0)return s2;
        if(m==0)return s1; 
         i = n-1;
         j = m-1;
        int carry = 0;

        while(i>=0 || j>=0){
             int sum = 0;
            if(i>=0){
                sum+=(s1.charAt(i)-'0');
                i--;
            }
            
              if(j>=0){
                sum+=(s2.charAt(j)-'0');
                j--;
                       }
            
            sum+=carry;
            carry = sum/2;
            ans.append(sum%2);
        }
        
        if(carry!=0)ans.append(carry);
        
        return ans.reverse().toString();
    }
}