#include <vector>

class Solution {
private:
    long long dfs(std::vector<std::vector<int>>& grid, int r, int c, int m, int n) {
        // Collect value and mark as visited by resetting to 0
        long long sum = grid[r][c];
        grid[r][c] = 0;
        
        // Direction vectors for 4-directional traversal
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1}; // Yahan curly braces {} aayenge

        
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            // Check boundary conditions and if it is unvisited land
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > 0) {
                sum += dfs(grid, nr, nc, m, n);
            }
        }
        return sum;
    }

public:
    int countIslands(std::vector<std::vector<int>>& grid, int k) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        int islandCount = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    // Get total weight/value of the current island
                    long long totalValue = dfs(grid, i, j, m, n);
                    
                    // Check if divisible by k
                    if (totalValue % k == 0) {
                        islandCount++;
                    }
                }
            }
        }
        
        return islandCount;
    }
};
