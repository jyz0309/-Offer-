/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s1;
        vector<int> result;
        if(!root) return result;
        s1.push(root);
        while(!s1.empty()){
            result.push_back(s1.top()->val);
            TreeNode* temp = s1.top();
            s1.pop();
            if(temp->left) s1.push(temp->left);
            if(temp->right) s1.push(temp->right);
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
