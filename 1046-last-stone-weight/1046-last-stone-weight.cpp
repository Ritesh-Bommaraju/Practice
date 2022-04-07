class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 1){
            return stones[0];
        }
        priority_queue<int> pq(stones.begin(), stones.end());
        while(pq.size() > 1){
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            if(x != y){
                pq.push(y-x);
            }
            // for case where x = y, we dont need to do anything, because we poped it and 
            // dgaf
            
            
            // when the last 2 elements are left, eventually you'll pop them so it will be empty 
            // i.e it is the last step
            if(pq.empty()){
                pq.push(y-x);
                return pq.top();
                
            }
        }
        return pq.top();
        
    }
};