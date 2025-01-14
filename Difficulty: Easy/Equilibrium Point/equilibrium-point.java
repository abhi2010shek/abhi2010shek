//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;

class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim()); // Inputting the testcases
        while (t-- > 0) {

            String line = br.readLine();
            String[] tokens = line.split(" ");

            // Create an ArrayList to store the integers
            ArrayList<Integer> array = new ArrayList<>();

            // Parse the tokens into integers and add to the array
            for (String token : tokens) {
                array.add(Integer.parseInt(
                    token)); // Use Integer.parseInt to parse int values
            }

            int[] arr = new int[array.size()];
            int idx = 0;
            for (int i : array) arr[idx++] = i;

            Solution obj = new Solution();

            // calling equilibriumPoint() function
            System.out.println(obj.findEquilibrium(arr));
            System.out.println("~");
        }
    }
}

// } Driver Code Ends


class Solution {
    // Function to find equilibrium point in the array.
    public static int findEquilibrium(int arr[]) {
        // code here
        int n = arr.length;
        int[] pre = new int[n];
        pre[0] = arr[0];
        for(int i=1;i<n;i++) {
            pre[i] = pre[i-1]+arr[i];
        }
        int[] suf = new int[n];
        suf[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--) {
            suf[i] = suf[i+1]+arr[i];
        }
        for(int i=0;i<n;i++) {
            if(pre[i]==suf[i]) return i;
        }
        return -1;
    }
}
