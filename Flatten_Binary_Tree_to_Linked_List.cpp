#include <bits/stdc++.h> 
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
  TreeNode<int> * cur=root;
  TreeNode<int> * Root=NULL;
  TreeNode<int> * Temp=new  TreeNode<int>(0) ;
  Root=Temp;
  while(cur!=NULL)
  {
      if(cur->left==NULL)
      {
          Temp->right=new TreeNode<int> (cur->data);
          Temp=Temp->right;
          cur=cur->right;
      }
      else
      {
          TreeNode<int> *temp=cur->left;
          while(temp->right!=NULL && temp->right!=cur)
          {
                temp=temp->right;
          }
          if(temp->right == cur)
          {
              temp->right=NULL;
              cur=cur->right;
          }
          else
          {
              Temp->right=new  TreeNode<int>(cur->data);
              Temp=Temp->right;
              temp->right=cur;
              cur=cur->left;
          }
      }
  }
    return Root->right;
}