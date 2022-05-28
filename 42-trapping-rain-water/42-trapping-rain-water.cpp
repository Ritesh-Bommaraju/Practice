class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxRight(n);
        vector<int> maxLeft(n);
        for(int i = 1; i < n; i++){
            maxLeft[i] = max(height[i-1], maxLeft[i-1]);
        }
        for(int i = n-2; i >= 0; i--){
            maxRight[i] = max(height[i+1], maxRight[i+1]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int waterLevel = min(maxLeft[i], maxRight[i]);
            if (waterLevel >= height[i]){
                ans += waterLevel - height[i];
            }
        }
        return ans;
    }
};
