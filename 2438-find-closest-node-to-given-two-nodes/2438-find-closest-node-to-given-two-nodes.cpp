class Solution {
    void bfs(vector<int>& edges, vector<int>& dist, int src) {
        int n = edges.size();
        vector<bool> visited(n, false);
        queue<pair<int, int>> q;
        q.push({src, 0});
        visited[src] = true;

        while (!q.empty()) {
            int node = q.front().first;
            int d = q.front().second;
            q.pop();

            dist[node] = d;

            int next = edges[node];
            if (next != -1 && !visited[next]) {
                visited[next] = true;
                q.push({next, d + 1});
            }
        }
    }

public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, -1), dist2(n, -1); 

        bfs(edges, dist1, node1);
        bfs(edges, dist2, node2);

        int minDist = INT_MAX;
        int result = -1;

        for (int i = 0; i < n; i++) {
            if (dist1[i] != -1 && dist2[i] != -1) {
                int maxDist = max(dist1[i], dist2[i]);
                if (maxDist < minDist) {
                    minDist = maxDist;
                    result = i;
                }
            }
        }

        return result;
    }
};
