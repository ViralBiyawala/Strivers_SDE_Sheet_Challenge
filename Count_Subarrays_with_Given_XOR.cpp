#include <bits/stdc++.h>

using namespace std;

int subarraysXor(vector<int> &arr, int x)//8 3 10 , 8
{
    unordered_map<long long, int> xorCount;//5:1,6:1
    int count = 0;//1
    long long xorSoFar = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        xorSoFar ^= arr[i];//14

        if (xorSoFar == x)//6 == 8
            count++;

        if (xorCount.find(xorSoFar ^ x) != xorCount.end())//14 ^ 8
            count += xorCount[xorSoFar ^ x];

        xorCount[xorSoFar]++;
    }

    return count;
}