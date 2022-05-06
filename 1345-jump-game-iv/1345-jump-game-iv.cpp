class Solution {
public:
    int minJumps(vector<int>& arr){
        //step 1;
        int n = arr.size();
        unordered_map<int, vector<int>> indicesOfValue;
        for (int i = 0; i < n; i++){
            indicesOfValue[arr[i]].push_back(i);
        }
        //step 2;
        vector<bool> visited(n);
        visited[0] = true;
        queue<int> q;
        q.push(0);
        int step = 0;
        //step 3
        while (!q.empty()) {
            for (int size = q.size(); size > 0; --size) {
                // step 4:
                int i = q.front();
                q.pop();
                if (i == n - 1){ // Reached to last index
                    return step;
                }
                // step 5;
                vector<int>& next = indicesOfValue[arr[i]];
                next.push_back(i - 1);
                next.push_back(i + 1);
                // step 6
                for (int j : next) {
                    if (j >= 0 && j < n && !visited[j]) {
                        visited[j] = true;
                        q.push(j);
                    }
                }
                // step 7
                indicesOfValue[arr[i]].clear(); // avoid later lookup indicesOfValue arr[i]
            }
            // step 8
            step++;
        }
        return 0;
    }
};