class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& v) {
        sort(v.begin(), v.end());
        int n = v.size();
        vector<int> ans(n);
        deque<int> dq;
        for (int i = 0; i < n; ++i){
		    dq.push_back(i);
        }
	    int chance = 0;
	    bool flag = false;
	    while (dq.size() > 0) {
		    if (!flag)
		    {
			    ans[dq.front()] = v[chance];
			    chance++;
			    dq.pop_front();
            }
		    else {
			    dq.push_back(dq.front());
			    dq.pop_front();
		    }
		    if (flag == true) {
                flag = false;
            }
		    else {
                flag = true;
            }
        }
        return ans;
    }
};