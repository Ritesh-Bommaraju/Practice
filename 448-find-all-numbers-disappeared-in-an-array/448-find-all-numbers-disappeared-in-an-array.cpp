class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for(auto& c : nums) 
            while(nums[c-1] != c) 
				swap(c, nums[c-1]); // swap till correct index place of c is not occupied by c itself
        for(int i = 1; i <= size(nums); i++)
            if(i != nums[i-1]) ans.push_back(i);  // correct index place of i is not occupied by i itself
        return ans;
        
    }
};

// For each element c, if the correct index place of c, i.e, nums[c-1] is not occupied by c, then we place c at its correct index place. But we dont want to lose number which was already present at nums[c-1]. So we swap it instead so the number at nums[c-1] occupies current element c & vice-versa.

// Let nums = [4,3,2,7,8,2,3,1]. The steps take place as -

// [7,3,2,4,8,2,3,1]
// [3,3,2,4,8,2,7,1]
// [2,3,3,4,8,2,7,1]
// [3,2,3,4,8,2,7,1]
// [3,2,3,4,1,2,7,8]
// [1,2,3,4,3,2,7,8]

// Index 4 & 5 are not occupied by their correct elements meaning the elements corresponding to those indices are missing