#include <bits/stdc++.h> 

int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vec(n,vector<int>(m,-1));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 && j==0) vec[i][j] = grid[i][j];
            else{
                int x  = grid[i][j]; 
                int var1 = 100000007, var2 = 100000007;

                if(i>0) var1 = vec[i-1][j];
                if(j>0) var2 = vec[i][j-1];

                vec[i][j] = min(x+var1,x+var2); 
 
            }
        }
    }

    return vec[n-1][m-1];

}