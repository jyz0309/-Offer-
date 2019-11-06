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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        TreeNode* cur = root;
        path1.push_back(cur);
        while(cur->val!=p->val){
                if(cur->val>p->val) cur = cur->left;
                else cur = cur->right;
                path1.push_back(cur);
        }
        cur = root;
        vector<TreeNode*> path2;
        path2.push_back(cur);
        while(cur->val!=q->val){
                if(cur->val>q->val) cur = cur->left;
                else cur = cur->right;
                path2.push_back(cur);
        }
        int i;
        int lowest;
        for(i = path1.size()-1;i>=0;i--){
            if(find(path2.begin(),path2.end(),path1[i])!= path2.end()){
                lowest = i;
                break;
            }
        }
        return path1[lowest];
    }
};
