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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        TreeNode *curr=root;
        TreeNode *left=nullptr;
        TreeNode *right=nullptr;
        if (curr->left) {
            left=curr->left;
        }
        if (curr->right) {
            right=curr->right;
        }
       
        curr->left=right;
        curr->right=left;
        invertTree(left);
        invertTree(right);
        return root;
    }
};
