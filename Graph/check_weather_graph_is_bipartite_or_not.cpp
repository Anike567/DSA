 bool check(int v ,vector<vector<int>>& graph,vector<int>&color){
        stack<int>q;
        q.push(v);
        color[v] = 0;

        while(!q.empty()){
            int node = q.top();
            q.pop();
            int clr = !color[node];

            for(auto i:graph[node]){
                if(color[i] == -1){
                    color[i] =clr; 
                    q.push(i);
                }
                else if(color[i] == color[node]){
                    return false;
                }
            }
        }   
        return true; 
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),-1);
        // this type of traversal because it is given that graph can also be disconnected
        for(int i=0;i<graph.size();i++){
            if(color[i] == -1){
                if(!check(i,graph,color)){
                    return false;
                }
            }
        }
        return true;
    }
