class Solution {
public:
    void helper(vector<char>& arr,int s, int e){
        if(s>=e){
            return;
        }
        swap(arr[s],arr[e]);
        return helper(arr,s+1,e-1);
    }
    void reverseString(vector<char>& s) {
        vector<char> v = s;
        helper(s,0,s.size()-1);
    }
};