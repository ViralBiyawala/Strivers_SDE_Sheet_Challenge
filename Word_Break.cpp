#include <bits/stdc++.h> 
bool wordBreak(vector < string > & arr, int n, string & s) {
    set<string> st;
    for(int i=0;i<arr.size();i++) st.insert(arr[i]);
    int i=0;
    string temp;
    int idx =-1;
    while(i<s.size()){
        temp+=s[i];
        if(st.find(temp)!=st.end()){
            idx = i;
            temp="";
        }
        i++;
    }
    if(idx==s.size()-1) return 1;
        return 0;
}