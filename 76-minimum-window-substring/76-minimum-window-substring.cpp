class Solution {
public:
     string minWindow(string large, string small) 
    {
        if(small.empty() || large.length()<small.length()) return "";
        
        int cnt = 0, reqt = small.length();
        vector<int> freq(128, 0); 
        for(char ch : small) ++freq[ch-'A'];
        int left=0, right=-1;
        int best_start=left, best_end=right;
        int min_length = INT_MAX;
        
        while(right<=int(large.length()))
        {
            //cout << left << "," << right << endl;
            if(cnt<reqt)
            {
                // move right pointer
                ++right;
                if(right==int(large.length())) return large.substr(best_start, best_end-best_start+1);
                int index = large[right] - 'A';
                if(freq[index]>0) ++cnt;
                --freq[index];
            }
            else
            {
                // move left pointer
                int index = large[left] - 'A';
                if(freq[index]==0) --cnt;
                ++freq[index];
                ++left;
            }
            
            // chech if a qualified answer is found
            if(cnt==reqt)
            {
                if(right-left+1<min_length)
                {
                    min_length = right-left+1;
                    best_start = left;
                    best_end   = right;
                    //cout << best_start << ", " << best_end << endl;
                }
            }
        }
        
        return large.substr(best_start, best_end-best_start+1);
    }
};