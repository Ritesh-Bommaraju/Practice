class Solution {
    public int majorityElement(int[] arr) {
        int n = arr.length;
        int candidate = -1;
        int votes = 0;
        for(int i = 0; i < n; i++){
            if(votes == 0){
                candidate = arr[i];
                votes = 1;
            }
            else{
                if(arr[i] == candidate){
                    votes++;
                }
                else{
                    votes--;
                }
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] == candidate){
                count++;
            }
        }
        if(count > n/2){
            return candidate;
        }
        return -1;
    }
};