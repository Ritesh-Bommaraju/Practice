bool comp(vector<int> &x, vector<int> &y){
        return x[1] < y[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), comp);
        // the comp ---> sorts based on end value;
        int n = points.size();
        int prev = points[0][1];
        int ans = 1;
        // if my prev end is in bounds with curr's then one arrow is enough;
        // else; broo... one more needed 
        for(int i = 1; i < n; i++){
            if(points[i][0] > prev){
                ans++;
                prev = points[i][1];
            }
        }
        return ans;   
    }
};
