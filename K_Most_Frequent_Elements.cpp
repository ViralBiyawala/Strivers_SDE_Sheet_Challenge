#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    vector<int>ans;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>mini;
    unordered_map<int,int>mp;
    for(int i = 0;i<arr.size();i++)
        mp[arr[i]]++;

    for(auto pair :mp){  
        if(mini.size()<k){
          mini.push({pair.second,pair.first});
        }
        else{
            if(mini.top().first<pair.second){
                mini.pop();
                mini.push({pair.second,pair.first});
            }
        }
    }
    while(!mini.empty()){
        ans.push_back(mini.top().second);
        mini.pop();
    }
    sort(ans.begin(),ans.end());
    return ans;
}