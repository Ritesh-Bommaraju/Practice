class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> rad[n];
        vector<int> bad[n];
    
        for(auto i : redEdges)
        {
            rad[i[0]].push_back(i[1]);
        }
        
        for(auto i : blueEdges)
        {
            bad[i[0]].push_back(i[1]);            
        }
        
        queue<pair<int,int>> q;
        q.push({0,1});
        q.push({0,-1});
        
        vector<pair<int,int>> dis(n,{INT_MAX,INT_MAX});
        dis[0] = {0,0};
        //dis[i].first->if we reach to the node i using blue color edge
        //dis[i].second->if we reach to the node i using red color edge

        int currDist=0;
        int red = -1;
        int blue = 1;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int node = q.front().first;
                int col = q.front().second;
                q.pop();
                //If we have reached to node with last edge Color blue=1
                if(col==blue)
                {
                    //Then we should move in adj of red color
                    for(auto v : rad[node])
                    {
                        if(dis[v].second>currDist+1)
                        {
                            q.push({v,-1});
                            dis[v].second = currDist+1;
                        }
                    }
                }
                else if(col==red)
                {
                    for(auto v : bad[node])
                    {
                        if(dis[v].first>currDist+1)
                        {
                            q.push({v,1});
                            dis[v].first = currDist+1;
                        }
                    }
                }
            }
            currDist++;
        }
        
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            int mn = min(dis[i].first,dis[i].second);
            if(mn==INT_MAX)
            {
                ans[i]=-1;
            }
            else
                ans[i] = mn;
                
        }
        return ans;
    }
};