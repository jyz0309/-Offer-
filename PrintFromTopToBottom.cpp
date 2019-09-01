class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> res;
        if(root == NULL) return res;
        q.push(root);
        while(!q.empty()){
            TreeNode *p = q.front();
            q.pop();
            res.push_back(p->val);
            if(p->left&&p->right){
                q.push(p->left);
                q.push(p->right);
            }
            else if(p->left) q.push(p->left);
            else if(p->right) q.push(p->right);
        }
        return res;
    }
};
