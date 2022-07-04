class Solution {
public:
    struct comp {
        bool operator()(const pair<int, string>& lhs, const pair<int, string>& rhs) const {
            if (lhs.first != rhs.first)
                return lhs.first < rhs.first;
            return lhs.second > rhs.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map <string, int> mp;
        for (string s: words){
            mp[s]++;
        }
        priority_queue <pair<int, string>, vector<pair<int, string>>, comp> pq;
        for (auto it: mp) {
            pq.push({it.second, it.first});
        }
        vector <string> res;
        while (k--) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};