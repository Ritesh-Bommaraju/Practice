class Solution {
public:
//     vector<pair<int,double>> v;
//         double t;
//         for(int i=0; i<position.size(); i++){
//             t = (double)(target-position[i])/speed[i];
//             v.push_back({position[i], t});
//             //cout << t << " ";
//         }
        
//         sort(v.begin(), v.end(), greater<pair<int,double>>());
//         stack<double> s;
//         for(auto p: v){
//             //cout << p.first << " ";
//             while(!s.empty() && s.top() >= p.second){
//                 s.pop();
//             }
//             s.push(p.second);
//         }
        
//         return s.size();
    int carFleet(int target, vector<int>& pos, vector<int>& speed){
        if (pos.empty() || speed.empty()) return 0;
        vector<pair<int, double>> intervals; // start position, time to reach target;
        for (int i = 0; i < pos.size(); i++){
            intervals.push_back(make_pair(pos[i], (double)(target - pos[i])/(double)(speed[i])));
        }
        sort(intervals.begin(), intervals.end());
        int ans = 1;
        int n = pos.size();
        double slowest = intervals[n-1].second;
        for(int i = n-2; i>=0; i--){
            if(intervals[i].second > slowest){
                ans++;
                slowest = intervals[i].second;
            }
        }
        return ans;
    }
};