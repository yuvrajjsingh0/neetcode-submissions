class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1, vector<pair<int, int>>{});

        for(auto &e : times) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<int> dist(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        dist[k] = 0;

        while(!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();

            if(d > dist[u]) continue;

            for(auto & [v, w] : adj[u]) {
                if(d + w < dist[v]) {
                    dist[v] = d + w;
                    pq.push({d+w, v});
                }
            }
        }

        int maxi = *max_element(dist.begin()+1, dist.end());

        return (maxi != INT_MAX) ? maxi : -1;
    }
};
