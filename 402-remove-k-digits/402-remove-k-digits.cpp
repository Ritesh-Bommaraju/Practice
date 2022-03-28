class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> st;
        for(int i = 0; i<n; i++){
            while(!st.empty() && k>0 && st.top()>num[i]){   
                st.pop();      
                k-=1;   
            }
            if(!st.empty() || num[i]!='0'){
                st.push(num[i]);
            }   
        }
        
//         for(auto c: num){
//             while(!st.empty() && k>0 && st.top()>c){   
//                 st.pop();      
//                 k-=1;   
//             }
//             if(!st.empty() || c!='0'){
//                 st.push(c);
//             }            
//         }
        // for cases like 123 .... no poping here at all so at last we have to delete 
        //elements from the back then.
        while(!st.empty() && k--){
            st.pop();
        }
        if(st.empty()){
            return "0";
        }
        while(!st.empty())
        {
            num[n-1] = st.top();
            st.pop();
            n-=1;
        }
        return num.substr(n);
    }
};