class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int,int>mp;
        int cnt = 0;
        int max_cnt = 0;
        int start_year;
        for(auto i:logs)
        {
            mp[i[0]]++;
            mp[i[1]]--;
        }
        for(auto i:mp)
        {
            cnt += i.second;
            if(cnt > max_cnt)
            {
                max_cnt = cnt;
                start_year = i.first;
            }
        }
        
        return start_year;
    }
};