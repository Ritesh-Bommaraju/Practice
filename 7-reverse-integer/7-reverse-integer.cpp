class Solution {
public:
    int reverse(int x) {
        if(x == 0){
            return 0;
        }
        int sign = 1;
        if(x < 0){
            sign = -1;
        }
        x = abs(x);
        queue<int> q;
        while(x > 0){
            q.push(x%10);
            x = x/10;
        }
        string ans = "";
        if(sign == -1){
            ans = "-";
        }
        while(!q.empty()){
            ans += to_string(q.front());
            q.pop();
        }
        if(stoll(ans) > INT_MAX || stoll(ans) < INT_MIN){
            return 0;
        }
        else{
            return stoi(ans);
        }
        
        
    }
};