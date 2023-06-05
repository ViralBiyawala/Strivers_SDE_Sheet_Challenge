#include <bits/stdc++.h>
using namespace std;

vector<vector<long long int>> printPascal(int numRows)
{
    vector<vector<long long int>> pascalTriangle(numRows);
    for (int i = 0; i < numRows; i++) {
        pascalTriangle[i].resize(i + 1);

        pascalTriangle[i][0] = 1; 
        pascalTriangle[i][i] = 1; 

        for (int j = 1; j < i; j++) {
            pascalTriangle[i][j] = pascalTriangle[i - 1][j - 1] + pascalTriangle[i - 1][j];
        }
    }
    return pascalTriangle;
}
