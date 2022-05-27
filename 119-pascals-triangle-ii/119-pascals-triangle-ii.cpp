class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> dp;
        vector<int> curr={1}; 
        dp.push_back(curr);
        if(rowIndex==0) return curr;
        for(int i=1;i<=rowIndex;i++){
            vector<int> curr(i+1);
            for(int j=0;j<curr.size();j++){
                if(j==0 || j==curr.size()-1) curr[j]=1; //first and last element of each row is 1
                else curr[j]=dp[i-1][j]+dp[i-1][j-1]; //All other elements are sum of the two elements above it
            }
            dp.push_back(curr);
            if(i==rowIndex) return curr; 
        }
        return curr;
    }
    
};