/*
题目要求：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
解题思路：使用递归，可以看出前序遍历的第一个数是根结点，然后通过根结点在中序遍历序列中找到左子树，再通过前序遍历找到左子树的根节点...进行递归
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* R(vector<int> a,int abegin,int aend,vector<int> b,int bbegin,int bend)
    {
        if(abegin>=aend||bbegin>=bend) return NULL;
        TreeNode *root = new TreeNode(a[abegin]);
        int i=bbegin;
        for(i;i<bend;i++){
            if(b[i]==a[abegin]) break;
        }
        root->left = R(a,abegin+1,abegin+i-bbegin+1,b,bbegin,i);
        root->right = R(a,abegin+i-bbegin+1,aend,b,i+1,bend);
        return root;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin){
        return R(pre,0,pre.size(),vin,0,vin.size());
    }
};
