// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq; // dist, node
        vector<long long> dist(n, 1e16);
        vector<int> ways(n, 0);
        dist[0] = 0; ways[0] = 1; pq.push({0, 0}); int mod = (1e9 + 7);
        while(!pq.empty()) {
            long long curr_dist = pq.top().first, curr_node = pq.top().second; pq.pop();
            if (curr_dist > dist[curr_node])    continue;
            for (auto it : adj[curr_node]) {
                int next_node = it.first, next_dist = it.second;
                if (dist[next_node] > curr_dist + next_dist) {
                    dist[next_node] = curr_dist + next_dist;
                    ways[next_node] = ways[curr_node];
                    pq.push({dist[next_node], next_node});
                }
                else if (dist[next_node] == curr_dist + next_dist) {
                    ways[next_node] = (ways[next_node] + ways[curr_node]) % mod;
                }
            }
        }
        return (int)ways[n-1] % mod;
    }
};
