void changeTree(BinaryTreeNode < int > * root) {
    if(!root) return;
    
    int sum=0;
    if(root->left) sum+=root->left->data;
    if(root->right) sum+=root->right->data;

    if(sum<root->data) {
        if(root->left) root->left->data=root->data;
        if(root->right) root->right->data=root->data;
    } 
    else if(sum>=root->data){
        root->data=sum;
    } 
    //traverse
    changeTree(root->left);
    changeTree(root->right);
    int total=0;
    if(root->left) total+=root->left->data;
    if(root->right) total+=root->right->data;
    if(root->left or root->right) root->data=total;
}  