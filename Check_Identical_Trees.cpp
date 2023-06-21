#include <bits/stdc++.h> 

bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    if(root1 == NULL && root2 == NULL)
        return true;
    if((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL))
        return false;
    if(root1->data != root2->data)
        return false;
    bool leftAns = identicalTrees(root1->left, root2->left);
    bool rightAns = identicalTrees(root1->right, root2->right);
    return leftAns && rightAns;
}