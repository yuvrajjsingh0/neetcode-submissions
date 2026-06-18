struct DSU {
    vector<int> parent, size;

    DSU(int n): parent(n), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if(parent[x] == x) return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if(a == b) return false;
        if(size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
};

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
        // vector<bool> visited(n, false);
        // vector<vector<int>> adj(n, vector<int>(0, 0));

        // for(auto &e : edges) {
        //     adj[e[0]].push_back(e[1]);
        //     adj[e[1]].push_back(e[0]);
        // }

        // int ct = 0;
        // for(int v = 0; v < n; v++) {
        //     if(!visited[v]) {
        //         dfs(v, adj, visited);
        //         ct++;
        //     }
        // }

        // return ct;

        int ans = 0;

        DSU dsu(n);

        for(auto &e : edges) {
            dsu.unite(e[0], e[1]);
        }

        set<int> unique_roots;
        for(int i = 0; i < n; i++) {
            unique_roots.insert(dsu.find(i));
        }

        return unique_roots.size();
    }
};
