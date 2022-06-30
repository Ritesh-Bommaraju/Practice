class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // double sum=0;
        // double min=INT_MAX;
        // for(int i=0;i<nums.size();i++){
        //     sum=0;
        //     for(int j=0;j<nums.size();j++){
        //         sum+=abs(nums[i]-nums[j]);
        //     }
        //     if(min>sum){
        //         min=sum;
        //     }
        // }
        // return (int)min;
        int n = nums.size(), steps = 0;
        nth_element(nums.begin(), nums.begin()+(n/2), nums.end()); //Fixing ths median element
        int median = nums[n/2];
        for(int i=0; i<n; i++){
            steps += abs(nums[i] - median);
        }
        return steps;
    }
    
};