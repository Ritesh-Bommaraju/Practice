class Solution {
public:
    int minSideJumps(vector<int>& obs) {
        int n = obs.size() - 1; // number of stops
        int total_jumps = 0;
        
        // init a 2d matrix as vis and mark mat[i][j] depicts -ith lane and jth point
        vector<vector<int>> vis(4,vector<int>(n+1,0));
        queue<pair<int,int>> q; // mana bfs queue mowa
        q.push({2,0}); // initial pos;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto [x,y] = q.front();
                q.pop();
                if(x>3||x<1||y>n||y<0||vis[x][y]==1||obs[y]==x) continue;  // eliminate the invalid points
                if(y==n){
                    return total_jumps - n; // gawd level thinking mowa
                }
                vis[x][y] = 1;
                q.push({x-1,y});  // one step down  
                q.push({x+1,y});  //one step up
                q.push({x-2,y});  //two steps down
                q.push({x+2,y});   //two steps up 
                q.push({x,y+1});   // mundhuke mingey
                
            }
            total_jumps++;
        }
        return -1;
    }
};