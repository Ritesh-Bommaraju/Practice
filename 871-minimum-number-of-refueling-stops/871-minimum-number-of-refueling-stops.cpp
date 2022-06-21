class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if(startFuel > target){
            return 0;
        }
        priority_queue<int> pq;
        int max_we_can_go = startFuel;
        int idx = 0;
        int stops = 0;
        while(max_we_can_go < target){
            while(idx < stations.size() and stations[idx][0] <= max_we_can_go){
                pq.push(stations[idx][1]);
                idx++;
            }
            if(pq.empty() == true){
                return -1;
            }
            max_we_can_go += pq.top();
            pq.pop();
            stops++;
        }
        return stops;
    }
};