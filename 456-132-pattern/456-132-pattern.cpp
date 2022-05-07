class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int second_max = INT_MIN;
        // start from the right and go towards left
        for(int i = n-1; i >= 0; i--){
            // the most important condition
            // here the top element of the stack acts as the max
            // the second_max is 2nd max and to 1 3 2 pattern 
            // you should find a number which is to the left of max and it should
            // be smaller than the largest element to the right of max.
            if(nums[i] < second_max){
                return true;
            }
            while(!st.empty() and nums[i] > st.top()){
                // if the nums[i] > top element of the stack
                // just pop and update the second_max
                if(st.top() > second_max){
                    second_max = st.top();
                }
                st.pop();
            }
            // else just push elements
            st.push(nums[i]);
        }
        return false;
    }
};