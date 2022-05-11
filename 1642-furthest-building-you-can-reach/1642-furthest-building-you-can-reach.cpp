class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int> pq;
        for(int i = 0; i < n - 1; i++){
            if(heights[i] >= heights[i+1]){
                continue;
            }
            int diff = heights[i+1] - heights[i];
            pq.push(diff);
            bricks -= diff;
            if(bricks >= 0){
                continue;
            }
            if(ladders == 0){
                return i;
            }
            
            bricks += pq.top();
            pq.pop();
            ladders--;
        }
        return n - 1;
    }
};