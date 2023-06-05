#include <bits/stdc++.h>
using namespace std;

void setZeros(vector<vector<int>> &matrix)
{
    int rowSize = matrix.size();
    int colSize = matrix[0].size();
    
    vector<int> zeroRows(rowSize, 0);
    vector<int> zeroCols(colSize, 0);
    
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            if (matrix[i][j] == 0) {
                zeroRows[i] = 1;
                zeroCols[j] = 1;
            }
        }
    }
    
    for (int i = 0; i < rowSize; i++) {
        if (zeroRows[i] == 1) {
            for (int j = 0; j < colSize; j++) {
                matrix[i][j] = 0;
            }
        }
    }
    
    for (int j = 0; j < colSize; j++) {
        if (zeroCols[j] == 1) {
            for (int i = 0; i < rowSize; i++) {
                matrix[i][j] = 0;
            }
        }
    }
}
