vector<int> bottomView(BinaryTreeNode<int> * root){
    map<int, int> hash;
    vector<int> ans;
    if(root == NULL) return ans;
    queue<pair<BinaryTreeNode<int>*, int>> q;
    pair<BinaryTreeNode<int>*, int> p = make_pair(root, 0);
    q.push(p);
    while(!q.empty()){
        int n = q.size();
        for(int i = 0; i < n; i++){
            pair<BinaryTreeNode<int>*, int> curr = q.front();
            q.pop();
            hash[curr.second] = curr.first->data;
            if(curr.first->left != NULL){
                pair<BinaryTreeNode<int>*, int> p = make_pair(curr.first->left, curr.second - 1);
                q.push(p);
            }
            if(curr.first->right != NULL){
                pair<BinaryTreeNode<int>*, int> p = make_pair(curr.first->right, curr.second + 1);
                q.push(p);
            }
        }
    }
    for(auto it : hash){
        ans.push_back(it.second);
    }
    return ans;
}