/* 
  detect(): Performs BFS to detect a cycle from the given source node.
Parameters:
adj[]: Adjacency list of the graph.
src: Starting node for BFS.
visited: Array to mark visited nodes.
Logic:
Initialize a queue with the source node and set its parent as -1.
For each adjacent node, check if it has already been visited:
If yes and it is not the parent, return true (cycle detected).
Otherwise, mark it as visited and continue BFS.
Returns true if a cycle is detected, otherwise false.
isCycle(): Iterates through all nodes, calling detect() for each unvisited node.
Parameters:
v: Number of vertices in the graph.
adj[]: Adjacency list of the graph.
Logic:
For each unvisited node, call detect().
If any component has a cycle, return true.
Returns true if a cycle is found in any component, otherwise false.


*/

bool detect(vector<int> adj[], int src, vector<int>& visited){
        queue<pair<int,int>>q;
        q.push(make_pair(src,-1));
        visited[src]=1;
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto adjenctNode : adj[node]){
                if(!visited[adjenctNode]){
                    q.push(make_pair(adjenctNode,node));
                    visited[adjenctNode]=1;
                }
                else if(adjenctNode != parent){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int v, vector<int> adj[]) {
        vector<int> visited(v, 0);  
        
        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                if (detect(adj, i, visited)) {
                    return true;
                }
            }
        }
        return false;  
    }
