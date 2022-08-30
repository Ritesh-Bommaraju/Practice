class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int count = 0;
        int lastp = 0, lastm = 0, lastg = 0;
        for(int i = 1; i < travel.size(); ++i){
            travel[i] += travel[i-1];
        }
        for(int i = 0; i < garbage.size(); ++i){
            count += garbage[i].size();
            for(auto c: garbage[i]){
                if(c == 'M'){
                    lastm = i;
                }
                else if(c == 'G'){
                    lastg = i;
                }
                else{
                    lastp = i;
                }
            }
        }
        if(lastm > 0){
            count+= travel[lastm-1];
        }
        if(lastg > 0){
            count+= travel[lastg-1];
        }
        if(lastp > 0){
            count+= travel[lastp-1];
        }
        return count;
    }
};