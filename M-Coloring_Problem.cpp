#include <bits/stdc++.h> 
bool isPossibleMthColor(vector<vector<int>>& adjMatrix, vector<int>& nodeColorVector, int nodeToColor, int color, int n) {
    for (int i = 0; i < n; i++)
        if (adjMatrix[nodeToColor][i] == 1)
            if (nodeColorVector[i] == color)
                return false;
    
    nodeColorVector[nodeToColor] = color;
    return true;
}
bool solveGraph(int nodeToColor, int n, int m, vector<int>& nodeColorVector, vector<vector<int>>& adjMatrix) {
    if (nodeToColor == n)
        return true;
    
    for (int i = 1; i <= m; i++) {
        if (isPossibleMthColor(adjMatrix, nodeColorVector, nodeToColor, i, n)) {
            if (solveGraph(nodeToColor + 1, n, m, nodeColorVector, adjMatrix))
                return true;
            
            nodeColorVector[nodeToColor] = 0;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>>& adjMatrix, int m) {
    int n = adjMatrix.size();
    vector<int> nodeColorVector(n, 0);
    
    if (solveGraph(0, n, m, nodeColorVector, adjMatrix))
        return "YES";
    
    return "NO";
}
