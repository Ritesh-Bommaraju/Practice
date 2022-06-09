class Solution {
public:
    vector<int> twoSum(vector<int>& ar, int target) {
        int start = 0;
        int end = ar.size()-1;
        
        while(start < end){
            if(ar[start] + ar[end] == target){
                return {start+1, end+1};
            }
            else if(ar[start] + ar[end] > target){
                end--;
            }
            else{
                start++;
            }
        }
        return {};
    }
};