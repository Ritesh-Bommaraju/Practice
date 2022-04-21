class Solution {
public:
    bool helper(vector<int>& arr, int i, vector<bool>&vis){
        bool ans = false;
        if( i < 0 || i >= arr.size() || vis[i] == true){
            return false;
        }
        if(arr[i] == 0){
            return true;
        }
        vis[i] = true;
        ans = (helper(arr, i + arr[i], vis) || helper(arr, i - arr[i], vis));
        return ans;
    }
    
    
    
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n,0);
        return helper(arr, start, vis);
        
        
    }
};