class Solution {
public:
    int maxDistance(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int dx[] = {-1, 0, 1, 0};
        int dy[] = { 0, 1, 0, -1};
        queue<pair<int, int>> q;
	    for (int i = 0 ; i < m ; i++) {
		    for (int j = 0 ; j < n ; j++)
		    {
			    if (matrix[i][j] == 1) {
				    q.push({i, j});
			    }
		    }
	    }
	    if (q.size() == n * m)
	    {
	    	return -1;
	    }
	    int ans = 0;
	    while (!q.empty()) 
        {
		    int size = q.size();
		    ans++;
		    while (size--)
		    {
			    int curr_i = q.front().first;
			    int curr_j = q.front().second;
			    q.pop();
			    for (int i = 0 ; i < 4; i++)
			    {
				    int new_i = curr_i + dx[i];
				    int new_j = curr_j + dy[i];
				    if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && matrix[new_i][new_j] == 0) {
					    q.push({new_i, new_j});
					    matrix[new_i][new_j] = 1;
				    }
			    }
		    }
	    }
	    return ans - 1;
    }
	// gurthupetko -- we are doing ans - 1 because, the bfs is doing an extra iteration even after all become 1
};