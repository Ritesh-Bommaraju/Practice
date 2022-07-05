class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        for(int i = 0; i < n; i++){
            s.insert(nums[i]);
        }
        int max_len = 0;
        for(int i = 0; i < n; i++){
            if(s.find(nums[i] - 1) != s.end()){
                continue;
            }
            else{
                int count = 0;
                int curr = nums[i];
                while(s.find(curr) != s.end()){
                    count++;
                    curr++;
                }
                max_len = max(max_len, count);
            }
        }
        return max_len;
    }
};