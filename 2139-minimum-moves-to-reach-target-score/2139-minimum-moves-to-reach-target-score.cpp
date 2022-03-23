class Solution {
public:
    int minMoves(int target, int k) {
        if(target == 1){
            return 0;
        }
        if(k == 0){
            return target - 1;
        }
        if(target%2 != 0){
            return 1 + minMoves(target - 1, k);
        }
        return 1 + minMoves(target/2, k-1);
        
    }
};