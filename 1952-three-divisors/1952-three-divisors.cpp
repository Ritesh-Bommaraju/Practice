class Solution {
public:
    bool isThree(int n) {
        set<int> s;
        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                s.insert(n/i);
                s.insert(i);
            }
        }
        if(s.size() == 3){
            return true;
        }
        return false;
    } 
};