class Solution {
public:
     vector<int> numOfBurgers(int ts, int cs) {
        if (ts%2==1 || ts/2<cs || ts/4>cs) return {};
        return {ts/2-cs, 2*cs-ts/2};
    }
};