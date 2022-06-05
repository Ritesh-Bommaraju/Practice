class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]] = i;
        }
        for(auto i : operations){
            int a = i[0];
            int b = i[1];
            // cout << a << " " << b << endl;
            nums[mp[a]] = b;
            mp[b] = mp[a];
        }
        return nums;
    }
};