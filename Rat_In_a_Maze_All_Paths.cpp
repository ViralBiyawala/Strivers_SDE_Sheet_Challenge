#include <bits/stdc++.h> 

void toMatrix(const std::string& move, std::vector<int>& v, int n) {
    std::vector<std::vector<int>> vv(n, std::vector<int>(n, 0));
    int r = 0, c = 0;
    vv[r][c] = 1;
    
    for (char ch : move) {
        if (ch == 'U')
            r--;
        else if (ch == 'D')
            r++;
        else if (ch == 'L')
            c--;
        else if (ch == 'R')
            c++;
        
        vv[r][c] = 1;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            v.push_back(vv[i][j]);
        }
    }
}

void solve(int r, int c, const std::vector<std::vector<int>>& maze, int n, std::vector<std::vector<int>>& vis, std::vector<std::vector<int>>& ans, const std::string& move) {
    if (r == n - 1 && c == n - 1) {
        std::vector<int> v;
        toMatrix(move, v, n);
        ans.push_back(v);
        return;
    }
    
    int directions[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    
    for (const auto& dir : directions) {
        int newR = r + dir[0];
        int newC = c + dir[1];
        
        if (newR >= 0 && newR < n && newC >= 0 && newC < n && vis[newR][newC] == 0 && maze[newR][newC] == 1) {
            vis[r][c] = 1;
            
            if (dir[0] == -1 && dir[1] == 0)
                solve(newR, newC, maze, n, vis, ans, move + 'U');
            else if (dir[0] == 1 && dir[1] == 0)
                solve(newR, newC, maze, n, vis, ans, move + 'D');
            else if (dir[0] == 0 && dir[1] == -1)
                solve(newR, newC, maze, n, vis, ans, move + 'L');
            else if (dir[0] == 0 && dir[1] == 1)
                solve(newR, newC, maze, n, vis, ans, move + 'R');
            
            vis[r][c] = 0;
        }
    }
}

std::vector<std::vector<int>> ratInAMaze(const std::vector<std::vector<int>>& maze, int n) {
    std::vector<std::vector<int>> ans;
    
    if (maze[0][0] == 0)
        return ans;
    
    std::string move = "";
    std::vector<std::vector<int>> vis(n, std::vector<int>(n, 0));
    solve(0, 0, maze, n, vis, ans, move);
    
    return ans;
}
