class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            arr[s[i]- 'a']++;
        }
        int ans = -1;
        for (int i = 0; i < s.length(); i++) {
            if (arr[s[i] - 'a'] == 1) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};