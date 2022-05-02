class Solution {
public:
    string minimizeResult(string en) {
        
        string str="",str1="",str2="";
        for(int i=0;i<en.size();i++){
            if(en[i]=='+'){
                str1=str;
                str="";
            }
            else{
                str+=en[i];
            }
        }
        
        str2=str;
        int fans=INT_MAX;
        int i1=0,j1=0;
        // cout<<str1<<" "<<str2<<" "<<endl;
        
        for(int i=1;i<=str1.size();i++){
            int len=str1.size();
            string x=str1.substr(len-i,i);//7
            string a=str1.substr(0,len-i);//24
            
            for(int j=1;j<=str2.size();j++){
                int len2=str2.size();
                string y=str2.substr(0,j);//3
                string b=str2.substr(j,len2-j);//8
                int x1=1,y1=1,t1=1,t2=1;
                cout<<x<<" "<<y<<" "<<a<<" "<<b<<endl;
                if(x!=""){
                    x1=stoi(x);//7   // 24 7 3 8
                }
                if(y!=""){
                    y1=stoi(y);//3
                }
                if(a!=""){
                    t1=stoi(a);//24
                }
                if(b!=""){
                    t2=stoi(b);//8
                }
                            
                int res=x1+y1;
 
                int ans=res*t1*t2;
                if(ans<fans){
                    fans=ans;
                    i1=i;
                    j1=j;
                }
            }
        }
        
        int in1=str1.size()-i1;
        str1.insert(in1,"(");
        str2.insert(j1,")");
        
        string ret=str1;
        ret.push_back('+');
        ret+=str2;
        return ret;
        // https://www.youtube.com/watch?v=m3JpdAW-_tw
        
    }
};