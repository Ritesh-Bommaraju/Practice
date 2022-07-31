class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        sort(grades.begin(), grades.end());

        int prevSum = 0, curSum = 0;
        int prevCount = 0, curCount = 0, res = 0;

        for(int grade: grades){
            curSum += grade;
            curCount++;
            if(curCount > prevCount && curSum > prevSum){
                res++;
                prevSum = curSum; prevCount = curCount;
                curSum = curCount = 0;
            }
        }

        return res;
    }
};