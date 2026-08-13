// https://leetcode.com/problems/path-with-minimum-effort/
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> diff(n, vector<int>(m, 1e9));
        pq.push({0, {0, 0}});
        while(!pq.empty()) {
            int curr_diff = pq.top().first, curr_x = pq.top().second.first, curr_y = pq.top().second.second;pq.pop();
            if (curr_x == n - 1 && curr_y == m - 1) return curr_diff;
            int dr[] = {-1, 0, +1, 0}, dc[] = {0, -1, 0, +1};
            for (int i = 0; i < 4; i++) {
                int next_x = curr_x + dr[i], next_y = curr_y + dc[i];
                if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m) {
                    int newEffort = max(curr_diff, abs(heights[next_x][next_y] - heights[curr_x][curr_y]));
                    if (diff[next_x][next_y] > newEffort) {
                        diff[next_x][next_y] = newEffort;
                        pq.push({newEffort, {next_x, next_y}});    
                    }
                }
            }
        }
        return -1;
    }
};
