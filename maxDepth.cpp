class Solution {
public:
    int max = 0;
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        depth(root,1);
        return max;
    }
    void depth(TreeNode* root,int n){
        if(n>max) max = n;
        if(root->left) depth(root->left,n+1);
        if(root->right) depth(root->right,n+1);
    }
};
