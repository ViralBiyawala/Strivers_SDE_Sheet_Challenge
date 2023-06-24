#include <bits/stdc++.h> 

class BSTiterator
{
    public: 
    stack<int> st;
    void inorder(TreeNode<int>* root)
    {
        if(root==NULL)
        return;

        inorder(root->right);
        st.push(root->data);
        inorder(root->left);
        return;
    }
    BSTiterator(TreeNode<int> *root)
    {
        inorder(root);
    }

    int next()
    {
        if(st.empty())
        return -1;
        else
        {
            int z=st.top();
            st.pop();
            return z;
        } 

    }

    bool hasNext()
    {
        if(st.empty())
        return false;
        else
        return true;
    }
};
