class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int> pq;
        for(int curr = 0; curr < n - 1; curr++){
            if(heights[curr] >= heights[curr+1]){
                continue;
            }
            int diff = heights[curr+1] - heights[curr];
            pq.push(diff);
            bricks -= diff;
            if(bricks >= 0){
                continue;
            }
            if(ladders == 0){
                return curr;
            }
            bricks += pq.top();
            pq.pop();
            ladders--;
        }
        return n - 1;
    }
};