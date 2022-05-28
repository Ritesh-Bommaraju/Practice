class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        queue<pair<int,int>> q;
        q.push({e[0],e[1]});
		
		//current moves
        int moves=1;
        int rows=maze.size();
        int cols=maze[0].size();
        
		//to move in all directions
        vector<vector<int>> dirs={{0,1},{1,0},{0,-1},{-1,0}};
		
        //mark the entrance  as visited
        maze[e[0]][e[1]]='+';
        
        while(!q.empty()){
            int size = q.size();
            for(int s = 0; s < size; s++){
                int curr_i = q.front().first;
                int curr_j = q.front().second;
                q.pop();
                
                for(int d = 0; d < 4; d++){
                    int new_i = curr_i + dirs[d][0];
                    int new_j = curr_j + dirs[d][1];
                    if(new_i < 0 || new_j < 0 || new_i >= rows || new_j >= cols || maze[new_i][new_j] == '+'){
                        continue;
                    }
                    if(new_i == 0 || new_j == 0 || new_i == rows - 1 || new_j == cols -1 ){
                        return moves;
                    }
                    maze[new_i][new_j] = '+';
                    q.push({new_i, new_j});
                    
                }
            }
            moves++;
        }
        return -1;
    }
};