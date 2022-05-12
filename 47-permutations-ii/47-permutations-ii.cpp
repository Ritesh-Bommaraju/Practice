class Solution {
public:
    void helper(set<vector<int>>&res,vector<int>& path,vector<int>& nums){
        if(path.size() == nums.size()){
            res.insert(path);
            return;
        }
        else{
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] != 111){
                    int temp = nums[i];
                    nums[i] = 111; 
                    path.push_back(temp);
                    helper(res, path, nums);
                    path.pop_back();
                    nums[i] = temp;
                }
                
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> path;
        helper(res, path, nums);
        vector<vector<int>> ans;
        for(auto ar : res){
            ans.push_back(ar);
        }
        return ans;
    }
    
};