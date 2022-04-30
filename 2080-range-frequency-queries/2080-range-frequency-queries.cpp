class RangeFreqQuery {
// public:
//     vector<int> ar;
//     RangeFreqQuery(vector<int>& arr) {
//         for(int i = 0; i < arr.size(); i++){
//             ar.push_back(arr[i]);
//         }
//     }
    
//     int query(int left, int right, int value) {
//         int count = 0;
//         for(int i = left; i<=right; i++){
//             if(ar[i] == value){
//                 count++;
//             }
//         }
//         return count;
//     }
private:
    unordered_map< int, vector<int> > mp;
public:
    RangeFreqQuery(vector<int>& arr) {
        for (int i=0; i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
    }
    int query(int left, int right, int value) {
        int first = lower_bound(mp[value].begin(),mp[value].end(),left)- mp[value].begin();
        int second = upper_bound(mp[value].begin(),mp[value].end(),right)- mp[value].begin();
        return second-first;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
// [12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56]
// [1, 2, 4]
// [0, 11, 33]
