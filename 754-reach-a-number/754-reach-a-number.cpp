class Solution {
public:
    // BFS ----- TLE
    // int reachNumber(int target) {
    //     queue<int> q;
    //     q.push(0);
    //     int count = 1;
    //     while(!q.empty()){
    //         int n = q.size();
    //         while(n--){
    //             int curr = q.front();
    //             q.pop();
    //             if(curr == target){
    //                 return count-1;
    //             }
    //             else{
    //                 vector<int> dirs;
    //                 dirs.push_back(curr+count);
    //                 dirs.push_back(curr-count);
    //                 for(int x : dirs){
    //                     if(x <= abs(target)){
    //                         q.push(x);
    //                     }
    //                 }
    //                 dirs.clear();
    //             }
    //         }
    //         count++;
    //     }
    //     return 0;
    // }
    
    long long bisect(int target){
        long low = 1;
        long high = (long)target;
        
        while (low < high){
            long mid = (low + high) /2;
            
            if (mid * (mid+1)/2 < target){
                low = mid + 1;
            } 
            else {
                high = mid;
            }
        }     
        return low;
    }
    int reachNumber(int target) {
        long long n = bisect(abs(target));
        while((n*(n+1)/2 % 2) != (abs(target) %2)){
            n++;
        }
        return int(n);
    }
};