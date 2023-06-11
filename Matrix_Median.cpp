#include<bits/stdc++.h>
//#include<cmath>
int getMedian(vector<vector<int>> &matrix)
{
    priority_queue<int> q;
    for(int i = 0; i< matrix.size(); i++)
        for(int j = 0; j < matrix[0].size(); j++)
            q.push(matrix[i][j]);

    int md = (q.size() / 2) ;
    while(md--)
        q.pop();
    return q.top();
}

