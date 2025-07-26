class Solution {
    vector<int> visited;
    vector<int> answer;
    vector<vector<int>> adj;

    void bfs(int node) {
        queue<int> q;
        q.push(node);
        visited[node] = 1;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            vector<bool> used(5, false);
            for (int neighbor : adj[curr]) {
                if (answer[neighbor] != 0) {
                    used[answer[neighbor]] = true;
                }
            }

            for (int f = 1; f <= 4; ++f) {
                if (!used[f]) {
                    answer[curr] = f;
                    break;
                }
            }

            for (int neighbor : adj[curr]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = 1;
                    q.push(neighbor);
                }
            }
        }
    }

public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        visited = vector<int>(n + 1, 0);
        answer = vector<int>(n + 1, 0);
        adj = vector<vector<int>>(n + 1);

        for (auto& p : paths) {
            int u = p[0], v = p[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                bfs(i);
            }
        }

        return vector<int>(answer.begin() + 1, answer.end());
    }
};
