class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        return a[1] < b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        int currentTotalTime = 0;
        sort(courses.begin(), courses.end(), cmp);
        priority_queue<int> pq;
        for(int i = 0; i < courses.size(); i++){
            if(currentTotalTime + courses[i][0] <= courses[i][1]){
                currentTotalTime += courses[i][0];
                pq.push(courses[i][0]);
            }
            else{
                if(!pq.empty() and pq.top() > courses[i][0]){
                    int x = pq.top();
                    pq.pop();
                    currentTotalTime -= x;
                    currentTotalTime += courses[i][0];
                    pq.push(courses[i][0]);
                }
            }
            
        }
        return pq.size();
    }
};