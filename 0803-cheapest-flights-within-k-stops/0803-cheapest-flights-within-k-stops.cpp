class Solution {
    typedef pair<int, pair<int, int>> pp; // (stop, (node, cost))
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);

        // Make adjacency list
        for (auto f : flights) {
            int u = f[0];
            int v = f[1];
            int w = f[2];
            adj[u].push_back({v, w});
        }

        vector<int> dist(n, 1e9);

        // pq - (stop, {v, weight})
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        pq.push({0, {src, 0}});
        dist[src] = 0;

        while (!pq.empty()) {
            int stop = pq.top().first;
            int node = pq.top().second.first;
            int d = pq.top().second.second;
            pq.pop();

            if (stop > k) continue;

            for (auto it : adj[node]) {
                int adjNode = it.first;
                int cost = it.second;
                if (d + cost < dist[adjNode]) {
                    dist[adjNode] = d + cost;
                    pq.push({stop + 1, {adjNode, d + cost}});
                }
            }
        }

        if (dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};
