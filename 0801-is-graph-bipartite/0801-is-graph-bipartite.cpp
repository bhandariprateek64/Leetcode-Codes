class Solution {
    vector<int> visited; 

    bool dfs(vector<vector<int>>& graph, int color, int node) {
        visited[node] = color;

        for (auto neighbor : graph[node]) {
            if (visited[neighbor] == -1) {
                if (!dfs(graph, !color, neighbor)) return false;
            } else if (visited[neighbor] == color) {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        visited = vector<int>(n, -1);

        for (int i = 0; i < n; ++i) {
            if (visited[i] == -1) {
                if (!dfs(graph, 0, i)) return false;
            }
        }

        return true;
    }
};
