class Solution {
public:
    int helper(vector<int>&A, int idx){
        int mx = A[0], mxidx = 0;
        for (int i = 0; i <= idx; i++) {
            if (A[i] > mx) {
                mxidx = i;
                mx = A[i];
            }
        }
        return mxidx;
    }
    
    vector<int> pancakeSort(vector<int>& A) {
        int n = A.size();
        vector<int>res;
        for (int i = n-1; i >= 0; i--) {
            int x = helper(A, i); // find max element index
            reverse(A.begin(), A.begin()+x+1); // reverse until the max element goes to 0th position
            reverse(A.begin(), A.begin()+i+1); // reverse the whole array so that the element reaches its correct position
            res.push_back(x+1); // for the first flip
            res.push_back(i+1); // for the second flip
        }
        return res;
    }
};