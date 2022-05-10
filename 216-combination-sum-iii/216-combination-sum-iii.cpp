class Solution {
public:
    void helper(vector<vector<int>>&res, int k, int target, int start, vector<int>&path){
        if(k == 0 && target == 0){
            res.push_back(path);
            return;
        }
        for(int i = start; i <= 9; i++){
            path.push_back(i);
            helper(res,k-1,target-i,i+1,path);
            path.pop_back();
        }
    }
    
    
    vector<vector<int>> combinationSum3(int k, int target) {
        vector<vector<int>> res;
        vector<int> path;
        helper(res, k, target,1,path);
        return res;
    }
};