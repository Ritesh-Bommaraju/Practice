bool comp(vector<int>&a, vector<int>&b){
    return (a[0] != b[0]) ? a[0] < b[0] : a[1] < b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int ans = 0;
        int currend = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            if(currend > intervals[i][0]){
                ans++;
                currend = min(currend, intervals[i][1]); 
            }
            else{
                currend = intervals[i][1];
            }
        }
        return ans;
    }
};
