class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
     vector<int> vec;
        unordered_set<int> hash;   // Hash table
        for(int i=0;i<nums.size();i++){
            if(hash.find(nums[i])==hash.end())  // If number not found in Hash table, add to hash table.
                hash.insert(nums[i]);
            else
                vec.push_back(nums[i]);        // If number found in hash table, add to vector.
        }
        return vec;
    }
};