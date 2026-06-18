class Solution {
public:
    void dfs(int v, vector<vector<int>>& adj, vector<bool> & visited) {
        if(visited[v]) return;
        visited[v] = true;
        for(auto &u : adj[v]) {
            dfs(u, adj, visited);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        vector<vector<int>> adj(n, vector<int>(0, 0));

        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int ct = 0;
        for(int v = 0; v < n; v++) {
            if(!visited[v]) {
                dfs(v, adj, visited);
                ct++;
            }
        }

        return ct;
    }
};
