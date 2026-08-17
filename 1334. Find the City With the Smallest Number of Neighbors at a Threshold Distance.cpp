// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>adjMat(n, vector<int>(n, 1e9));
                for (auto it : edges) {
                    adjMat[it[0]][it[1]] = it[2];
                    adjMat[it[1]][it[0]] = it[2];
                }
                for (int k = 0; k < n; k++) {
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                            if (adjMat[i][k] == 1e9 || adjMat[k][j] == 1e9) continue;
                            adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
                        }
                    }
                }
                int count = 0, connCity = n, city = -1;
                for (int i = 0; i < n; i++) {
                    count = 0;
                    for (int j = 0; j < n; j++) {
                        if (i !=j && adjMat[i][j] <= distanceThreshold)   count++;
                    }
                    if (count <= connCity) {
                        connCity = count; city = i;
                    }
                }
                return city;
    }
};
