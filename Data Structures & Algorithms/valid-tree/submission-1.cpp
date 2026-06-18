struct DSU {
    vector<int> parent, size;

    DSU(int n): parent(n), size(n) {
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
    bool validTree(int n, vector<vector<int>>& edges) {
        DSU dsu(n);

        for(auto &e : edges) {
            if(!dsu.unite(e[0], e[1])) return false;
        }

        int unique_roots = 0;
        for(int i = 0; i < n; i++) {
            if(dsu.find(i) == i) unique_roots++;
        }

        return unique_roots == 1;
    }
};
