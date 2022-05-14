class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed){
        if (pos.empty() || speed.empty()) return 0;
        vector<pair<int, double>> intervals; // start position, time to reach target;
        for (int i = 0; i < pos.size(); i++){
            intervals.push_back(make_pair(pos[i], (double)(target - pos[i])/(double)(speed[i])));
        }
        sort(intervals.begin(), intervals.end());
        int n = pos.size();
        stack<double> st;
        for(int i = n-1; i>=0; i--){
            if(st.empty() or intervals[i].second > st.top()){
                st.push(intervals[i].second);
            }
        }
        return st.size();
    }
    // if a car behind me takes more time than me to reach target, itll be of a seperate fleet, else
    // all other cars which take less time than me, behind me , form a fleet with me.....
    
};