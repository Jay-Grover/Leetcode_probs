// https://takeuforward.org/plus/dsa/problems/find-the-mst-weight?source=strivers-a2z-dsa-track&tab=submissions//
class Solution{
    public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<pair<int,int>, 
        vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<int> visited(V, 0);
        int sum = 0;
        pq.push({0,0});
        while(!pq.empty()) {
            auto t = pq.top(); pq.pop();

            if (visited[t.second] == 1)    continue;
            visited[t.second] = 1;
            sum += t.first; // wt, node
            for (auto it: adj[t.second]) {
                auto node = it[0]; auto wt = it[1];
                if (visited[node] == 0) {
                    pq.push({wt, node});
                }
            }
        }
        return sum;
    }
};
