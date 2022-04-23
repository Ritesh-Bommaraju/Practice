class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1 && trust.size() == 0){
            return 1;
        }
        if(n==2 && trust.size() == 0){
            return -1;
        }
        vector<int> v(n+1, 0);
        for(int i = 0; i < trust.size(); i++){
            // cout << trust[i][0] << endl;
            v[trust[i][0]] = -1;
            v[trust[i][1]]+=1;
        }
        int ans = -1;
        // for(int i = 0; i < v.size();i++){
        //     cout << v[i] << endl;
        // }
        // cout << "--" << endl;
        for(int i = 0; i < v.size();i++){
            if(v[i] == n-1){
                ans = i;
                return ans;
            }
        }
        return ans;
    }
};