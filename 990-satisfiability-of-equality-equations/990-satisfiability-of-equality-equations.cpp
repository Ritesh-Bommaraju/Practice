class Solution {
public:
    int parent[26];
    
    int find_par(int x){
        if(x != parent[x]){
            parent[x] = find_par(parent[x]);
        }
        return parent[x];
    }
    
    bool equationsPossible(vector<string>& equations) {
        for(int i = 0; i < 26; i++){
            parent[i] = i;
        }
        for(string e :equations){
           if(e[1] == '='){
               parent[find_par(e[0] - 'a')] = find_par(e[3] - 'a');
           } 
        }
        for(string e :equations){
           if(e[1] == '!'){
               int a = find_par(e[0] - 'a');
               int b = find_par(e[3] - 'a');
               if(a == b){
                   return false;
               }
           } 
        }
        return true;
    }
};
