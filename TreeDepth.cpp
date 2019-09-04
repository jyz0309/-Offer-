/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    int deep;
    int TreeDepth(TreeNode* pRoot)
    {
        if(!pRoot) return 0;
        deep++;
        int left = TreeDepth(pRoot->left)+1;
        int right = TreeDepth(pRoot->right)+1;
        return max(left,right);
    }
};
