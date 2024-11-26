//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Sorting {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int g = 0; g < t; g++) {
            String[] str = (br.readLine()).trim().split(" ");
            int arr[] = new int[str.length];
            for (int i = 0; i < str.length; i++) arr[i] = Integer.parseInt(str[i]);
            System.out.println(new Solution().circularSubarraySum(arr));
            // System.out.println("~");
        }
    }
}
// } Driver Code Ends


class Solution {

    // a: input array
    // n: size of array
    // Function to find maximum circular subarray sum.
    public int kadane(int arr[])
    {
        int maxEnding=arr[0];
        int res=0;
        for(int i=1;i<arr.length;i++)
        {
            maxEnding=Math.max(maxEnding+arr[i],arr[i]);
            res=Math.max(res,maxEnding);
        }
        return res;
    }
    public int circularSubarraySum(int arr[]) 
    {
        int n=arr.length;
        int normal_sum=kadane(arr);
        if(normal_sum<0)
        return normal_sum;
        
        int total_sum=0;
        for(int i=0;i<n;i++)
        {
            total_sum+=arr[i];
            arr[i]=-1*arr[i];
        }
        int circular_sum=total_sum+kadane(arr);
        return Math.max(normal_sum,circular_sum);
    }
}
