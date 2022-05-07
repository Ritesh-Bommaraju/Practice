class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tem) {
        int n = tem.size();
        vector<int> ans(n, 0);
        stack<pair<int,int>> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() and tem[i] > st.top().first){
                ans[st.top().second] = i - st.top().second;
                st.pop();
                
            }
            st.push({tem[i],i});
        }
        return ans;
    }
};