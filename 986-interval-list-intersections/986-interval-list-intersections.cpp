class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int m = firstList.size();
        int n = secondList.size();
        
        if(n == 0 || (m == 0 && n == 0) || m == 0){
            return {};
        }
        vector<vector<int>> ans;
        int ptr1 = 0;
        int ptr2 = 0;
        while(ptr1 <= m-1 && ptr2 <= n-1){
            int a1 = firstList[ptr1][0];
            int a2 = firstList[ptr1][1];
            
            int b1 = secondList[ptr2][0];
            int b2 = secondList[ptr2][1];
            
            int merge_start = max(a1, b1);
            int merge_end = min(a2, b2);
            
            if(merge_start <= merge_end){
                ans.push_back({merge_start, merge_end});
            }
            // what to increment ?
            if(a2 < b2){
                ptr1++;
            }
            else{
                ptr2++;
            }
        }
        return ans;
        
    }
};