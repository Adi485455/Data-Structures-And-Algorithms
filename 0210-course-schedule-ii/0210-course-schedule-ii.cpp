class Solution {
public:

   // So this is this is the actual question of the topological sorting here we need to give the order in which the sorting takes place and the result we obtain

   // So for this we needed the actually detect the cycle first and then only do the topological sort and then give the result

   bool dfs_cycle(int src,vector<vector<int>>& edges,vector<bool>&vis,vector<bool>&path){
    vis[src]=true;
    path[src]=true;
    for(int i=0;i<edges.size();i++){
        int v = edges[i][0];
        int u = edges[i][1];

        if(u == src){
            if(!vis[v]){
                if(dfs_cycle(v,edges,vis,path)) return true;
            }else if(path[v]){
                return true;
            }
        }
    }
    path[src]=false;
    return false;
   }


   void topo_sort(int src,vector<vector<int>>& edges,vector<bool>&vis,stack<int>&s){
    vis[src]=true;
    for(int i =0;i<edges.size();i++){
        int v = edges[i][0];
        int u = edges[i][1];
        if(u==src){
        if(!vis[v]){
            topo_sort(v,edges,vis,s);
        }
    }
    }
    s.push(src);
   }

    vector<int> findOrder(int numCourses, vector<vector<int>>& edges) {
        int n=numCourses;
        vector<int>ans;

        vector<bool>vis(numCourses,false);
        vector<bool>path(numCourses,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs_cycle(i,edges,vis,path)) return ans;
            }
        }

        vis.assign(n,false);
        stack<int>s;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                topo_sort(i,edges,vis,s);
            }
        }

        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};