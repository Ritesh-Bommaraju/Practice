class Solution {
public:
    int findTheDistanceValue(vector<int>& A, vector<int>& R, int d) {
        int size1= A.size(), size2= R.size();
        int res = size1;
        for(int i = 0; i < size1; i ++) {
            for(int j = 0; j < size2; j ++) {
                if(abs(A[i] - R[j]) <= d) {
                    res --;
                    break;
                }
            }
        }
        return res;
    }
};