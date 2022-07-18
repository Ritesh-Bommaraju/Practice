class Solution {
public:
    bool isRobotBounded(string ins) {
        int x = 0;
        int y = 0;
        bool north = true;
        bool south = false;
        bool west = false;
        bool east = false;
        
        for(char ch : ins){
            if(ch == 'L'){
                if(north){
                    north = false;
                    west = true;
                }
                else if(south){
                    south = false;
                    east = true;
                }
                else if(east){
                    east = false;
                    north = true;
                }
                else if(west){
                    west = false;
                    south = true;
                }
            }
            else if(ch == 'R'){
                if(north){
                    north = false;
                    east = true;
                }
                else if(south){
                    south = false;
                    west = true;
                }
                else if(east){
                    east = false;
                    south = true;
                }
                else if(west){
                    west = false;
                    north = true;
                }
            }
            else{
                if(north){
                    y++;
                }
                else if(south){
                    y--;
                }
                else if(east){
                    x++;
                }
                else if(west){
                    x--;
                }
            }
        }
        if(x == 0 && y == 0){
            return true;
        }
        if(north == true){
            return false;
        }
        return true;
    }
};