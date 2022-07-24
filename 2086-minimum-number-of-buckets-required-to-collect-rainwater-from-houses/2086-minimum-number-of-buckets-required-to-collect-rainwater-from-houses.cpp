class Solution {
public:
    int minimumBuckets(string street) {
        int n = street.size();
        int res = 0;
        for(int i = 0; i < n; i++){
            if(street[i] == 'H'){
                if(i-1>= 0 && street[i-1] == 'B'){
                    continue;
                }
                if(i+1 < n && street[i+1] == '.'){
                    res++;
                    street[i+1] = 'B';
                    continue;
                }
                if(i-1 >= 0 && street[i-1] == '.'){
                    res++;
                    street[i-1] = 'B';
                    continue;
                }
                return -1;
            }
        }
        return res;
        
    }
};