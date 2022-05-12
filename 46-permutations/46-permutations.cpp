class Solution {
public:
    void helper(vector<int>& nums,vector<int>& path,vector<vector<int>>&ans){
        if(path.size() == nums.size()){
            ans.push_back(path);
            return;
        }
        else{
            for(int i = 0; i < nums.size(); i++){
                if(find(path.begin(), path.end(), nums[i]) != path.end()){
                    continue;
                }
                path.push_back(nums[i]);
                helper(nums, path, ans);
                path.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        helper(nums, path, ans);
        return ans;
    }
    
    
};