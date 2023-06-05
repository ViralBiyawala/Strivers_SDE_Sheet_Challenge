#include <bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int rowStart = 0;
    int rowEnd = n - 1;
    int colStart = 0;
    int colEnd = m - 1;

    while (rowStart < rowEnd && colStart < colEnd) {
        int prev = mat[rowStart + 1][colStart];

        // Move elements of top row from left to right
        for (int i = colStart; i <= colEnd; i++) {
            int curr = mat[rowStart][i];
            mat[rowStart][i] = prev;
            prev = curr;
        }
        rowStart++;

        // Move elements of right column from top to bottom
        for (int i = rowStart; i <= rowEnd; i++) {
            int curr = mat[i][colEnd];
            mat[i][colEnd] = prev;
            prev = curr;
        }
        colEnd--;

        // Move elements of bottom row from right to left
        if (rowStart <= rowEnd) {
            for (int i = colEnd; i >= colStart; i--) {
                int curr = mat[rowEnd][i];
                mat[rowEnd][i] = prev;
                prev = curr;
            }
            rowEnd--;
        }

        // Move elements of left column from bottom to top
        if (colStart <= colEnd) {
            for (int i = rowEnd; i >= rowStart; i--) {
                int curr = mat[i][colStart];
                mat[i][colStart] = prev;
                prev = curr;
            }
            colStart++;
        }
    }
}
