class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& edges) {
        vector<int> incoming(V, 0);
        vector<vector<int>> adj(V);
       int answer=0;
        queue<int> q;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[v].push_back(u);
            incoming[u]++;
        }

       
        for (int i = 0; i < V; i++) {
            if (incoming[i] == 0) {
                q.push(i);
            }
        }

        
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            answer++;

            for (int x : adj[t]) {
                incoming[x]--;
                if (incoming[x] == 0) {
                    q.push(x);
                }
            }
        }
        return answer==V;
    }
};