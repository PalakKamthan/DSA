class Solution {
    void solve(int i, int j, vector<vector<int>>& a, int n, vector<string>& ans, string move, vector<vector<int>>& vis) {
        // Base case: reached destination
        if (i == n - 1 && j == n - 1) {
            ans.push_back(move);
            return;
        }

        vis[i][j] = 1; // mark visited

        //Down
        if (i + 1 < n && !vis[i + 1][j] && a[i + 1][j] == 1)
            solve(i + 1, j, a, n, ans, move + 'D', vis);

        //Left
        if (j - 1 >= 0 && !vis[i][j - 1] && a[i][j - 1] == 1)
            solve(i, j - 1, a, n, ans, move + 'L', vis);

        //Right
        if (j + 1 < n && !vis[i][j + 1] && a[i][j + 1] == 1)
            solve(i, j + 1, a, n, ans, move + 'R', vis);

        //Up
        if (i - 1 >= 0 && !vis[i - 1][j] && a[i - 1][j] == 1)
            solve(i - 1, j, a, n, ans, move + 'U', vis);

        vis[i][j] = 0; // unmark visited (backtrack)
    }

public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        if (maze[0][0] == 1)
            solve(0, 0, maze, n, ans, "", vis);

        sort(ans.begin(), ans.end()); // ensure lexicographical order
        return ans;
    }
};
