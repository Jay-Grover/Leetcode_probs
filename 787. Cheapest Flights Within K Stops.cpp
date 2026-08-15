// https://leetcode.com/problems/cheapest-flights-within-k-stops/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for (int i = 0; i < flights.size(); i++) {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        queue<pair<int, pair<int, int>>> pq; // stops, node, dist
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        pq.push({0, {src, 0}});
        while (!pq.empty()) {
            int curr_hop = pq.front().first, curr_node = pq.front().second.first, curr_dist = pq.front().second.second; pq.pop();
            if (curr_hop > k)   continue;
            for (auto it : adj[curr_node]) {
                int next_node = it.first, next_dist = it.second;
                if (dist[next_node] > curr_dist + next_dist && curr_hop <= k) {
                    dist[next_node] = curr_dist + next_dist;
                    pq.push({curr_hop + 1, {next_node, dist[next_node]}});
                }
            }
        }
        if (dist[dst] == 1e9)   return -1;
        return dist[dst];
    }
};
};
