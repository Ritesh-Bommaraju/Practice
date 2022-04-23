class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> mp;
        for(int i = 0; i < tasks.size(); i++){
            mp[tasks[i]]++;
        }
        int ans = 0;
        for(auto it : mp){
            if(it.second == 1){
                return -1;
            }
            if(it.second % 3 == 0){
                ans+= it.second/3;
            }
            // else if(it.second % 2 == 0){
            //     ans+= it.second/2;
            // }
            else{
                ans+= it.second/3 + 1;
            }
        }
        return ans;
    }
};