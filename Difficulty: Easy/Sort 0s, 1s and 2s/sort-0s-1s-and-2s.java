//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            String input = br.readLine();
            String[] inputArray = input.split("\\s+");
            int a[] = new int[inputArray.length];

            for (int i = 0; i < a.length; i++) a[i] = Integer.parseInt(inputArray[i]);

            Solution ob = new Solution();
            ob.sort012(a);

            for (int num : a) {
                System.out.print(num + " ");
            }
            System.out.println();
            System.out.println("~");
        }
    }
}


// } Driver Code Ends
class Solution {
    // Function to sort an array of 0s, 1s, and 2s
    public void sort012(int[] arr) {
        // code here
        int c0=0,c1=0;
        for(int i:arr)
        {
            if(i==0)
            c0++;
            if(i==1)
            c1++;
        }
        Arrays.fill(arr,2);
        for(int i=0;i<c0;i++)
        {
            arr[i]=0;
        }
         for(int i=c0;i<c0+c1;i++)
        {
            arr[i]=1;
        }
        
    }
}

//{ Driver Code Starts.
// } Driver Code Ends