/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIn=0;
        return buildTreek(preorder,inorder,preIn,0,inorder.size()-1);
    }
    TreeNode* buildTreek(vector<int>& preorder, vector<int>& inorder,int &preIn,int left,int right) {
        if (left>right) {
            return nullptr;
        }
        int root=preorder[preIn++];
        int inIn=left;
        for (int i=left;i<=right;i++) {
            if (root==inorder[i]) {
                inIn=i;
                break;
            }
        }
        TreeNode* roote =new TreeNode(root);
        roote->left=buildTreek(preorder,inorder,preIn,left,inIn-1);
        roote->right=buildTreek(preorder,inorder,preIn,inIn+1,right);
        return roote;

    }
};
