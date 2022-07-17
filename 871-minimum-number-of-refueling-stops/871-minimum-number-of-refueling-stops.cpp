class Solution {
public:
    // int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    //     if(startFuel > target){
    //         return 0;
    //     }
    //     priority_queue<int> pq;
    //     int max_we_can_go = startFuel;
    //     int idx = 0;
    //     int stops = 0;
    //     while(max_we_can_go < target){
    //         while(idx < stations.size() and stations[idx][0] <= max_we_can_go){
    //             pq.push(stations[idx][1]);
    //             idx++;
    //         }
    //         if(pq.empty() == true){
    //             return -1;
    //         }
    //         max_we_can_go += pq.top();
    //         pq.pop();
    //         stops++;
    //     }
    //     return stops;
    // }
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int idx=0,stock = 0,ans=0;
        priority_queue<int> pq;
        pq.push(startFuel);
        while(!pq.empty())
        {
            int currFuel = pq.top();
            pq.pop();
            stock+=currFuel;
            if(stock >= target)
                return ans;
            while(idx < stations.size() and stock >= stations[idx][0])
            {
                pq.push(stations[idx][1]);
                idx++;
            }
            ans++;
        }
        return -1;
    }
};
