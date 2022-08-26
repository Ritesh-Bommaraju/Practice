class Solution {
public:
    bool check(int n){
        return (n&(n-1))==0;
    }
    bool permutation(string s,int left,int right)
    {
        if(left>right){
            return false;
        }
        if(left==right)
        {
            char ch = s[0];
            if(ch!='0' && check(stoi(s))){
                return true;
            }
            else{
                return false;
            }
        }
        bool flag;
        for(int i=left;i<=right;i++)
        {
            swap(s[left],s[i]);
            flag = permutation(s,left+1,right);
            if(flag)
                return true;
            swap(s[left],s[i]);
        }
        return flag;
    }
    bool reorderedPowerOf2(int n) {
	
        if(n==1 or n==2) return true;
        string s = to_string(n);
        n = s.size();
        return permutation(s,0,n-1);
    }
};