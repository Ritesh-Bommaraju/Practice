class Solution {
public:
    int solve(string s)
    {
        char ch = s[0];
        for(int i = 1; i < s.size(); i++)
        {
            ch = min(ch,s[i]);
        }
        int count = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ch)
            {
                count++;
            }
        }
        return count;        
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> v1,v2,v3;
        for(int i = 0; i < queries.size(); i++)
        {
            v1.push_back(solve(queries[i]));
        }
        for(int i = 0; i < words.size();i++)
        {
            v2.push_back(solve(words[i]));
        }
        sort(v2.begin(),v2.end());
        for(int i = 0; i < v1.size(); i++)
        {
            int ans = upper_bound(v2.begin(),v2.end(),v1[i]) - v2.begin();
            v3.push_back(v2.size()-ans);
        }
        return v3;
    }
};