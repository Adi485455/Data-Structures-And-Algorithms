class Solution {
public:

    // for this question as the concept is the neighbour are gonna be rotten so w need the BFS tranversal 
    // The starting point is  can be start from the any of the rotten or say just gonna start from the all the rotten oranges we have in the grid (so need to push the all the rotten oranges in the queue with the time as the 0)
    // then we gonna perform the basic BFS transversal until the queue becomes empty just pop the front element then push its neighbour to the queue (one imp distinction just update the time count by 1 every time)
    // And the imp distinction from the normal BFS with the adjecancy list is the we need to check in the all direction for the neighbours like in the up,down,left & right 
    // And at last we just need to check for the any left of the unrotten or the fresh oranges if found just return -1;

    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        queue<pair<pair<int,int>,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=true;
                }
            }
        }

        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int t=q.front().second;
            q.pop();


            ans=max(ans,t);

            if(i-1 >= 0 && !vis[i-1][j] && grid[i-1][j]==1){
                q.push({{i-1,j},t+1});
                vis[i-1][j]=true;
            }
            if(i+1 < n && !vis[i+1][j] && grid[i+1][j]==1){
                q.push({{i+1,j},t+1});
                vis[i+1][j]=true;
            }
            if(j-1 >= 0 && !vis[i][j-1] && grid[i][j-1]==1){
                q.push({{i,j-1},t+1});
                vis[i][j-1]=true;
            }
            if(j+1 < m && !vis[i][j+1] && grid[i][j+1]==1){
                q.push({{i,j+1},t+1});
                vis[i][j+1]=true;
            }
        }
        // Check if any fresh oranges remain
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1 ){
                    return -1;
                }

            }

        }
        return ans;
    }
};