class Solution {
public:
    int count = 0;
    void helper(int n, int last){
        if(n == 0){
            count++;
            return;
        }
        for(int i = 0; i < 5; i++){
            if(i >= last){
                helper(n-1, i);
            }
        }
    }
    
    int countVowelStrings(int n) {
        helper(n, 0);
        return count;
    }
};