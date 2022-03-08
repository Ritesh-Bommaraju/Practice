// { Driver Code Starts
// C++ implementation to convert a
// sentence into its equivalent
// mobile numeric keypad sequence
#include <bits/stdc++.h>
using namespace std;
string printSequence(string input);
// Driver function
int main()
{
	int t;
	cin>>t;
	cin.ignore();
	while(t--)
    {
        string s;
        getline(cin,s);
        cout<<printSequence(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends


string printSequence(string S)
{
    unordered_map<char,string> map;
   int i;
   string a;
   string b;
   map['A']="2";
   map['B']="22";
   map['C']="222";
   map['D']="3";
   map['E']="33";
   map['F']="333";
   map['G']="4";
   map['H']="44";
   map['I']="444";
   map['J']="5";
   map['K']="55";
   map['L']="555";
   map['M']="6";
   map['N']="66";
   map['O']="666";
   map['P']="7";
   map['Q']="77";
   map['R']="777";
   map['S']="7777";
   map['T']="8";
   map['U']="88";
   map['V']="888";
   map['W']="9";
   map['X']="99";
   map['Y']="999";
   map['Z']="9999";
   map[' ']="0";
   
  
   for(i=0;S[i]!='\0';i++)
   {
       b=map[S[i]];
      a.append(b);
       
   }
   return a;
}