class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue <pair<int,int>> pq;
        int left = 0;
        int right = 0;
        while(right < nums.size()){
            pq.push({nums[right], right});
            if(right - left + 1 < k){
                right++;
            }
            else if(right - left + 1 == k){
                // we care only about the index associated with the top most element being 
                // out of bounds of window size
                while(pq.top().second < left){
                    pq.pop();
                }
                ans.push_back(pq.top().first);
                right++;
                left++;
            }
        }
        return ans;
    }
};