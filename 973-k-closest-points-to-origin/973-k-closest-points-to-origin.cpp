class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>>heap;
        vector<vector<int>>ans;
        for(int i=0; i<points.size(); i++)
        {
            int dist = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            heap.push(make_pair(-1*dist, i));
            //since C++ pq stl default is a max heap and we want minimum distance, multiply with -1.
        }
        while(k--)
        {
            int i = heap.top().second;
            heap.pop();
            ans.push_back({points[i][0], points[i][1]});
        }
        return ans;
    }
};