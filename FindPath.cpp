class Solution {
public:
    vector<vector<int> > buffer;
    vector<int> tmp;
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root==NULL) return buffer;
        tmp.push_back(root->val);
        if(expectNumber-root->val==0&&!root->left&&!root->right) buffer.push_back(tmp);
        FindPath(root->left,expectNumber-root->val);
        FindPath(root->right,expectNumber-root->val);
        if(tmp.size()!=0) tmp.pop_back();
        return buffer;
    }
};
