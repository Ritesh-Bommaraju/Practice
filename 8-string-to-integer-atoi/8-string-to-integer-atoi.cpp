class Solution {
public:
    int myAtoi(string s) {
        int long long ans = 0;
        int i = 0;
        while(s[i] == ' '){
            i++;
        }
        bool isnegative = false;
        if(s[i] == '-'){
            i++;
            isnegative = true;
        }
        else if(s[i] == '+'){
            i++;
        }
        while(s[i] >= '0' && s[i] <= '9'){
            ans = ans*10 + s[i]-'0';
            if(ans >= INT_MAX && isnegative == false){
                ans = INT_MAX; 
                break;
            }
            else if(ans > INT_MAX && isnegative == true){
                ans = INT_MIN; 
                break;
            }
            i++;
        }
        if(isnegative == true){
            ans = ans * -1;
        }
        return ans;
        
        
    }
};