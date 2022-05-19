//just tried to explain as much as I can. Upvote if it helped. thanks
class Solution {
  
    long lcmOfAC;
    long lcmOfAB;
    long lcmOfBC;
    long lcmOfABC;
  
    public int nthUglyNumber(int n, int a, int b, int c) {
        
      lcmOfAC  = lcm(a,c);
      lcmOfAB  = lcm(a,b);
      lcmOfBC  = lcm(b,c);
      lcmOfABC = lcm(a,lcmOfBC);
      
      int left = 1;
      int right = Integer.MAX_VALUE;
      
      
      //how BS works here: If our count of ugly numbers before the value of 'mid'
      //is greater or equal we decrease right. 
      //And when we have exactly 'n-1' on the left side, our answer is 'left', 
      //meaning that left is the number which is at ((n-1)+1) th position.
      
      
      /// MOST IMPORTANT THING TO UNDERSTAND HERE IS: HOW DOES HOW MANY UGLY NUMBERS ARE THERE BEFORE 'MID' GIVES THE NTH UGLY NUMBER??? WE ARE JUST COUNTING NUMBERS RIGHT?? HOW DOES IT EVEN WORK??
      /*
        LET ME EXPLAIN: FOR EXAMPLE TEST-CASE 1: 
        
        N = 3, A = 2, B = 3, C = 5. CLEAR HERE.
        
        NOW TAKE A SERIES OF N NATURAL NUMBERS. LIKE:
        
        1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21...
        
        NOW FOR 2 IT'S: 2 4 6 8 10 12 14 16...
                 FOR 3: 3 6 9 12 15 18
                 FOR 5: 5 10 15 20 25.....
                 
        //WITH THIS LINE: long total = mid/a + mid/b + mid/c - mid/lcmOfAB - mid/lcmOfBC - mid/lcmOfAC + mid/lcmOfABC;        
        //WE ARE ADDING EVERY UNIQUE MULTIPLE OF ALL OF THE THREE ONLY ONE TIME.
        
        //SO OUR FINAL N-NATURAL NUMBER SERIES BECOMES:  //EVERY DUPLICATE IS REMOVED.
          1, 2, 3, 4, 5, 6, 8, 9, 10... (SAME AS PROVIDED IN TEST CASE) //EVERY NUMBER IS UNIQUE AND INCREASING. //ONE IS INCLUDED BECAUSE LEFT = 1.
          
        //KEEP-IN-MIND, BY COUNTING WE ARE SAYING - HOW MANY UGLY NUMBERS APPEAR BEFORE THIS 'MID'
        // WE ARE SAYING IF THERE ARE "n-1" UGLY NUMBERS BEFORE THAN "n" IS OUR ANSWER. HERE "LEFT" IS THAT "N"

        // SO IF OUR MID IS FINALLY AT LET SAY '5', WE DECREASE OUR RIGHT TO 'MID' (RIGHT = MID),
        // BECAUSE TOTAL NUMBERS BEFORE 5 ARE 3 (1,2,3,4).
        
        //THIS PROCESS KEEPS GOING UNTIL MID IS AT 3, AND COUNT < N WHICH MEANS LEFT = MID+1 (3+1) = 4;
        
        //TRY TO THINK IN YOUR WAY A LITTLE MORE IF YOU STILL DON'T GET IT.
          
      */
      
      
      
      while(left<right){
        
        int mid = left+(right-left)/2;

        if(count(mid, a, b, c, n)){
          right = mid;
        }
        
        else
          left = mid+1;        
      }
      
      return left;      
    }
  
   
    
    boolean count(long mid, long a, long b, long c, long n){
      
      
		/*
		*   mid/a = total number of multiples 'a' till chosen 'mid'. //same for 'b' and 'c'.
		*  
		*   mid/lcm(a,b) = total number of duplicate multiples that appear for series of 'a' and 'b'  // same for (b,c) & (c,a)      
		*   
		*   now because we subtract all the common mulitples  that appear for all three 'a' & 'b' & 'c'

		*   we'll have to again add those who appear in all three series again (check below comment)
		*/      
		 /* example: 

				for 2:- 2 4 6 8 10 12 14
				for 3:- 3 9 12 15 18 21
				for 4:- 4 8 12

				//now notice that '12' is common in all of them, it should be counted only 'once', not 'thrice'.
				// same goes for '4', it appeared 2 times, we want to count only 'one' time.

				// this is why we subtracted  all common duplicates first, then lastly add the lcm(a,lcm(b,c)) //simply say -  lcm(a,b,c)
				// we do this last 'add' step because we have already subtracted all duplicates that are common.
				// so to add those who are common in "all three series" (like 12 here), we do this last  '+ lcm(a,b,c)' step.
		*/
		
     
      long total = mid/a + mid/b + mid/c - mid/lcmOfAB - mid/lcmOfBC - mid/lcmOfAC + mid/lcmOfABC;
      
      return total >= n;
      
    }
  
  
    static long gcd(long a,long b){
      while(b>0){
        a%=b;
        //swap
        long temp = a;
        a = b;
        b = temp;
      }
      return a;
    }

    static long lcm(long a, long b){
      
      return a/gcd(a,b)*b;
    }
}