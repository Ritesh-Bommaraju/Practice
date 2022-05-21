class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        if(coins.size()==1) return amount%coins[0]==0 ? amount/coins[0] : -1;
        queue<int> bfs;
        int count = 0;
        bfs.push(amount);
        
        unordered_set<int> done; 
        
        while(!bfs.empty()){
           int size = bfs.size();
            for(int i =0 ;i<size; i++){
                auto curr = bfs.front();
                bfs.pop();
                for(auto i : coins){
                    if(curr-i == 0) return count+1;
                    else if(done.find(curr-i)!=done.end()) continue;
                    else if(curr-i > 0) {
                        bfs.push(curr-i);
                        done.insert(curr-i);
                    }
                    else continue;
                }
            }
            count++;
        }
        
        return -1;
        
    }
};