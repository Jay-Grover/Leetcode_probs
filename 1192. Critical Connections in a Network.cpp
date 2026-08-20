//https://leetcode.com/problems/critical-connections-in-a-network/
class Solution {
private:
    int time = 0;
    void dfs(vector<int> adj[], vector<int> &vis, vector<int> &tin, vector<int> &low, vector<vector<int>> &bridge, int n,int node, int parent) {
        vis[node] = 1;
        tin[node] = low[node] = time;
        time++;
        for (auto it : adj[node]) {
            if (it == parent) continue;
            if (vis[it] == 0) {
                dfs(adj, vis, tin, low, bridge, n, it, node);
                low[node] = min(low[node], low[it]);
                if (low[it] > tin[node])    bridge.push_back({it, node});

            }
            else {
                low[node] = min(low[node], low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for (auto it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n, 0);
        vector<int> tin(n); vector<int> low(n);
        vector<vector<int>> bridge;
        dfs(adj, vis, tin, low, bridge, n, 0, -1);
        return bridge;
    }
};
