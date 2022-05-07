class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int second_max = INT_MIN;
        for(int i = n-1; i >= 0; i--){
            if(nums[i] < second_max){
                return true;
            }
            while(!st.empty() and nums[i] > st.top()){
                if(st.top() > second_max){
                    second_max = st.top();
                }
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};