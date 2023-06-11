#include <bits/stdc++.h> 

bool ispossible(int mid,vector<int> &positions,int c){
    int cnt=1,res=positions[0];
    for(int i=0;i<positions.size();i++){
  if(positions[i]-res>=mid){
      cnt++;
      if(cnt==c)return true;
      res=positions[i];
  }
    }
return false;
}
int chessTournament(vector<int> positions , int n ,  int c){
    int low=1;
    sort(positions.begin(),positions.end());
    int maxi=INT_MIN;
    int mini=INT_MAX;
    for(int i=0;i<n;i++){
        maxi=max(maxi,positions[i]);
        mini=min(mini,positions[i]);
    }
    int high=maxi-mini;
    while(low<=high){
        int mid=(low+high)/2;
        if(ispossible(mid,positions,c)){
            low=mid+1;
        }
        else high=mid-1;
    }
    return high;
}