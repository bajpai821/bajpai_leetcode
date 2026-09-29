class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Base pruning: length of the path must be even to be balanced
        if ((m + n - 1) % 2 != 0) return false;
        // Cannot start with ')' or end with '('
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;
        
        // Memoization table: mem[i][j][balance]
        // Max balance possible can't exceed the path length (m + n)
        vector<vector<vector<int>>> mem(m, vector<vector<int>>(n, vector<int>(m + n, -1)));
        
        return dfs(0, 0, 0, grid, mem);
    }

private:
    bool dfs(int i, int j, int bal, vector<vector<char>>& grid, vector<vector<vector<int>>>& mem) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Out of bounds check
        if (i >= m || j >= n) return false;
        
        // Update balance for the current cell
        bal += (grid[i][j] == '(') ? 1 : -1;
        
        // If balance becomes negative, we have more ')' than '(', which is invalid
        if (bal < 0) return false;
        
        // Target cell reached: check if all brackets are perfectly balanced
        if (i == m - 1 && j == n - 1) return bal == 0;
        
        // Return cached result if already calculated
        if (mem[i][j][bal] != -1) return mem[i][j][bal];
        
        // Explore moving right or moving down
        bool right = dfs(i, j + 1, bal, grid, mem);
        bool down = dfs(i + 1, j, bal, grid, mem);
        
        return mem[i][j][bal] = (right || down);
    }
};
