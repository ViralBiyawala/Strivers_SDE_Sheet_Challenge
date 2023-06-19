#include<bits/stdc++.h>
vector<int> getTopView(TreeNode<int> *root) {
    vector<int> ans;
    if(!root) return ans;
    map<int,int> mp;
    queue<pair<TreeNode<int>*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        int sz=q.size();
        for(int i=0 ; i<sz ; i++){
            auto node=q.front().first;
            int line=q.front().second;
            if(mp[line]==0) 
                mp[line]=node->val;
            if(node->left) 
                q.push({node->left,line-1});
            if(node->right) 
                q.push({node->right,line+1});
            q.pop();
        }
    }
    for(auto x:mp)
        ans.push_back(x.second);
    return ans;
}