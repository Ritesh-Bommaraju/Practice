class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        double sum=0;
        double min=INT_MAX;
        for(int i=0;i<nums.size();i++){
            sum=0;
            for(int j=0;j<nums.size();j++){
                sum+=abs(nums[i]-nums[j]);
            }
            if(min>sum){
                min=sum;
            }
        }
        return (int)min;
    }
    
};