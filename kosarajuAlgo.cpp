class Solution{
public:
    void dfs(stack<int> &s, vector<int> adj[], int node, vector<int> &vis) {
        vis[node] = 1;
        for (auto it : adj[node])   if (vis[it] == 0)    dfs(s, adj, it, vis);
        s.push(node);
    }
    void dfs_now(vector<int> adj[], int node, vector<int> &vis) {
        vis[node] = 1;
        for (auto it : adj[node])   if (vis[it] == 0)    dfs_now(adj, it, vis);
    }
    int kosaraju(int n, vector<int> adj[]){
        vector<int> vis(n, 0);
        // dfs get stack
        stack<int> s;
        for (int i = 0; i < n; i++) if(vis[i] == 0) dfs(s, adj, i, vis);
        // reverse the direction
        vector<int> revAdj[n];
        for (int i = 0; i < n; i++) {
            vis[i] = 0;
            for (auto it : adj[i]) {
                revAdj[it].push_back(i);
            }
        }
        // remove one stack add one
        int count = 0;
        while(!s.empty()) {
            int node = s.top(); s.pop();
            if (vis[node] == 0) {
                dfs_now(revAdj, node, vis);
                count++;
            }
        }
        return count;
    }
};
