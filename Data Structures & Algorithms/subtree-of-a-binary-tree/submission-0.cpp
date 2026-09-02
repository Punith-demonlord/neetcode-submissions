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
//go to bottom check if ma
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root&&!subRoot) {
            return true;
        } 
        if (!root) {
            return false;
        }
        if (!subRoot) {
            return true;
        }
        return isEquivalent(root,subRoot)||isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
    }
    bool isEquivalent(TreeNode* root,TreeNode* subRoot) {
        if (!root||!subRoot) {
            if (!root&&!subRoot) {
                return true;
            }
            return false;
        }
        if (root->val==subRoot->val&&isEquivalent(root->left,subRoot->left)&&isEquivalent(root->right,subRoot->right)) {
            return true;
        }
        return false;
    }
};
