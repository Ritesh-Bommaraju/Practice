class Solution {
public:
    void helper(int idx, int target,vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds){
        if(idx == arr.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        if(arr[idx] <= target){
            ds.push_back(arr[idx]);
            helper(idx, target - arr[idx], arr, ans, ds);
            ds.pop_back();
        }
        helper(idx + 1, target, arr, ans, ds);
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        helper(0,target,candidates,ans,ds);
        return ans;
        
    }
};