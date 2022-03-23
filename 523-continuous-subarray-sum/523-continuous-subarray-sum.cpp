class Solution {
public:
    bool checkSubarraySum(vector<int>& A, int k) {
        unordered_map<int, int> seen = {{0, -1}};
        int cur = 0;
        for (int i = 0; i < A.size(); ++i) {
            cur = cur + A[i];
            int r = cur % k;
            if (seen.count(r) == 0) {
                seen.insert({r, i});
            }
            if (i - seen[r] > 1) {
                return true;
            }
            // cout << i << seen[r] << endl;
        }
        return false;
        
    }
};