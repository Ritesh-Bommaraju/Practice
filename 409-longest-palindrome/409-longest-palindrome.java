class Solution {
    public int longestPalindrome(String s) {
        if(s.length() == 1){
            return 1;
        }
        int[] freq = new int[128];        
        for(char c:s.toCharArray()){
            ++freq[c];
        }
        int OddGroup = 0;
        for(int i:freq){
            OddGroup += i & 1;
        }
        return s.length() - OddGroup + (OddGroup > 0 ? 1:0);
    }
}