class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        for(int i = 0; i < intervals.size(); i++){
            if(ans.empty()){
                ans.push_back(intervals[i]);
            }
            else{
                vector<int> &v = ans.back();
                int prev_end = v[1];
                int curr_start= intervals[i][0];
                int curr_end = intervals[i][1];
                if(curr_start <= prev_end){
                    v[1] = max(curr_end, prev_end);
                }
                else{
                    ans.push_back(intervals[i]);
                }
            }
        }
        return ans;
    }
};