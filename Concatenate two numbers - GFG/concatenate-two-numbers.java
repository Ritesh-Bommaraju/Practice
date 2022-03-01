// { Driver Code Starts
//Initial Template for Java
import java.io.*;
import java.util.*; 
class GFG{
    public static void main(String args[]) throws IOException { 
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        
        while(t-- > 0){
            
            String input_line[] = read.readLine().trim().split("\\s+");
            int N = Integer.parseInt(input_line[0]);
            int X = Integer.parseInt(input_line[1]);
            
            input_line = read.readLine().trim().split("\\s+");
            int numbers[]= new int[N];
            for(int i = 0; i < N; i++)
                numbers[i] = Integer.parseInt(input_line[i]);

            Solution ob = new Solution();
            long ans = ob.countPairs(N, X, numbers); 
            System.out.println(ans);
        }
    } 
} // } Driver Code Ends


//User function Template for Java
class Solution 
{ 
    long countPairs(int N, int X, int numbers[]) 
    { 
        HashMap<String,Integer> hm=new HashMap<>();
        for(int z:numbers)
        {
           String s=Integer.toString(z);
           hm.putIfAbsent(s,0);
           hm.put(s,hm.get(s)+1);
        }
        int count=0;
        String x=Integer.toString(X);
        for(String k:hm.keySet())
        {
            if(k.length()>=x.length()) continue;
            int index=x.indexOf(k);
            String req=x.substring(k.length());
            if(index==0 && hm.containsKey(req))
            {
                int val=hm.get(req);
                if(req.equals(k))
                count+=(val*(val-1));
                else
                count+=val*hm.get(k);
            }
        }
        return count;
    }
} 