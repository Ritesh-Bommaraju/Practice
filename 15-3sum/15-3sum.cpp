class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if(nums.size() < 3){
            return res;
        }
        if(nums[0] > 0){
            return res;
        }
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int low = i + 1;
            int high = nums.size() - 1;
            while(low < high){
                int sum = nums[i] + nums[low] + nums[high];
                if(sum > 0){
                    high--;
                }
                else if(sum < 0){
                    low++;
                }
                else{
                    res.push_back({nums[i], nums[low], nums[high]});
                    int last_low_occurence = nums[low] , last_high_occurence = nums[high];  
                    //Now again, to avoid duplicate triplets, we have to navigate to last occurences of num[low] and
                    //num[high] respectively
                    while(low < high && nums[low] ==last_low_occurence){
                        low++;
                    }
                    while(low < high && nums[high] ==last_high_occurence){
                        high--;
                    }
                }
            }
        }
        return res;
    }
};