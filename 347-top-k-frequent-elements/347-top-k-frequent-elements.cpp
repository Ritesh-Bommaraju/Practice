class Solution {
public:
    struct comp{
        bool operator()(const pair<int,int> &p1, const pair<int,int> &p2){
            return p1.second > p2.second;
            
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int, int> freq;
        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
            
        }
        priority_queue< pair<int,int>, vector<pair<int,int>>,comp > pq;
        for(auto x : freq){
            if(pq.size() < k){
                pq.push({x.first, x.second});
            }
            else{
                pair<int,int> temp = pq.top();
                if(x.second > temp.second){
                    pq.pop();
                    pq.push({x.first, x.second});
                }
                
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            pair<int,int> ar = pq.top();
            ans.push_back(ar.first);
            pq.pop();
        }
        return ans;
        
        
    }
};