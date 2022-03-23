class Solution {
public:
    int brokenCalc(int start, int target) {
        if (start > target)
            return start - target;
        int count = 0;
        while(start != target){
            if(target > start && target%2 == 0){
                target = target/2;
                count++;
            }
            else{
                target++;
                count++;
            }
        }
        return count;
        
    }
    // if (startValue > target)
    //         return startValue - target;
    //     int count = 0;
    //     while (startValue != target)
    //         if (target % 2 == 0 and target > startValue)
    //             target /= 2,
    //                 count++;
    //         else
    //             target++, count++;
    //     return count;
};