class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> words;
        set<string> vis;
        queue<string> q;
        for(auto x : wordList){
            words.insert(x);
        }
        vis.insert(beginWord);
        q.push(beginWord);
        int res = 0;
        while(!q.empty()){
            int n = q.size();
            res++;
            for(int i = 0; i < n; i++){
                string x = q.front();
                q.pop();
                if(x == endWord){
                    return res;
                }
                string temp;
                for(int i = 0; i < x.size(); i++){
                    temp = x;
                    for(int j = 'a'; j <= 'z'; j++){
                        temp[i] = j;
                        if(words.count(temp) > 0 and vis.count(temp) == 0){
                            q.push(temp);
                            vis.insert(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};