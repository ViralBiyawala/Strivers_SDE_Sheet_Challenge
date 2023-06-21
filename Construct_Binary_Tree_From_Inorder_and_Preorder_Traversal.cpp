#include<bits/stdc++.h>
void createMapping(vector<int> &inorder, unordered_map<int,vector<int>> &nodeToIndex, int n)
{
    for(int i=0;i<n;i++)
        nodeToIndex[inorder[i]].push_back(i);
}
    
TreeNode<int>* solve(vector<int> &inorder, vector<int> &preorder, int n, int &preIndex, int inOrderStart, int inOrderEnd, unordered_map<int,vector<int>> &nodeToIndex)
{
    if(preIndex>=n || inOrderStart > inOrderEnd)
        return NULL;
    int element=preorder[preIndex++];
    TreeNode<int>* root=new TreeNode<int>(element);
    int position=-1;
    if(nodeToIndex[element][0]==INT_MIN)
    {
        position=nodeToIndex[element][1];
        nodeToIndex[element][1]=INT_MIN;
    }
    else
    {
        position=nodeToIndex[element][0];
        nodeToIndex[element][0]=INT_MIN;
    }
    root->left=solve(inorder, preorder, n, preIndex, inOrderStart, position-1, nodeToIndex);
    root->right=solve(inorder, preorder, n, preIndex, position+1, inOrderEnd, nodeToIndex);
    return root;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    int n=inorder.size();
    int preIndex=0;
    unordered_map<int,vector<int>> nodeToIndex;
    createMapping(inorder, nodeToIndex, n);
    TreeNode<int>* ans=solve(inorder, preorder, n, preIndex, 0, n-1, nodeToIndex);
    return ans;
}