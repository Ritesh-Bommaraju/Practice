// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxEvents(int start[], int end[], int N) {
        vector<pair<int,int>> AR(N);
        for(int i=0; i<N; i++)
        {
            AR[i].first = start[i];
            AR[i].second = end[i];
        }
        sort(AR.begin(),AR.end());
        priority_queue <int, vector<int>, greater<int>> pq;
        int i = 0, res = 0, d = 0;
        while (pq.size() > 0 || i < N) {
            if (pq.size() == 0){
                d = AR[i].first;
            }
            while (i < N && AR[i].first <= d){
                pq.push(AR[i++].second);
            }
            pq.pop();
            ++res;
            ++d;
            while (pq.size() > 0 && pq.top() < d){
                pq.pop();
            }

        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];

        Solution ob;
        cout << ob.maxEvents(start,end,N) << endl;
    }
    return 0;
}  // } Driver Code Ends