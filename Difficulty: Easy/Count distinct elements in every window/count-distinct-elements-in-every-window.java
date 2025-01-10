//{ Driver Code Starts
import java.io.*;
import java.util.*;
import java.util.HashMap;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t > 0) {
            String line = br.readLine();
            String[] tokens = line.split(" ");

            ArrayList<Integer> array = new ArrayList<>();

            for (String token : tokens) {
                array.add(Integer.parseInt(token));
            }

            int[] arr = new int[array.size()];
            int idx = 0;
            for (int i : array) arr[idx++] = i;

            int k = Integer.parseInt(br.readLine());

            ArrayList<Integer> ans = new Solution().countDistinct(arr, k);

            for (Integer val : ans) System.out.print(val + " ");
            System.out.println();

            t--;
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


class Solution {
    ArrayList<Integer> countDistinct(int arr[], int k) {
        // code here
        ArrayList<Integer> ans =new ArrayList<Integer>();
        HashMap<Integer,Integer>map=new HashMap<Integer,Integer>();
        int key=0;
        int n=arr.length;
        for(int i=0;i<k;i++)
        {
           map.put(arr[i],map.getOrDefault(arr[i],0)+1);
        }
        ans.add(map.size());
        for(int i=k;i<n;i++)
        {
            map.put(arr[i],map.getOrDefault(arr[i],0)+1);
            int value=map.get(arr[key]);
            if(value==1)
            map.remove(arr[key]);
            else{
                map.put(arr[key],map.get(arr[key])-1);
            }
            
            key++;
            ans.add(map.size());
        }
        return ans;
    }
}
