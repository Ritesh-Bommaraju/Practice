// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> a){
        int n =  a.size();
        int m = a[0].size();
    
        int total = n*m;
    
        int i = 0;
        int j = 0;
    
        char dir = 'r';
    
        while(i < n && j < m) {
            if(a[i][j]) {
                if(dir == 'r') dir = 'd';
                else if(dir == 'd') dir = 'l';
                else if(dir == 'l') dir = 'u';
                else dir = 'r';
                
                a[i][j] = 0;
            }
            else {
                if(dir == 'r'){
                    if(j+1 < m) j++;
                    else break;
                }
                else if(dir == 'd'){
                    if(i+1 < n) i++;
                    else break;
                }
                else if(dir == 'l') {
                    if(j-1 >= 0) j--;
                    else break;
                }
                else {
                    if(i-1 >= 0) i--;
                    else break; 
                } 
            }
            
           
        }
        return {i,j};
    }

};

// { Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}  // } Driver Code Ends