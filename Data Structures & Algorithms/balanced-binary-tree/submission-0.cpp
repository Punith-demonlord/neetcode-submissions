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
    int height=0;
    bool isBalanced(TreeNode* root) {
        return balance(root).first;
    }

    pair<bool,int> balance(TreeNode* root) {
        if (!root) {return {true,0};}
        int left=balance(root->left).second;
        int right =balance(root->right).second;
        if (balance(root->left).first&&balance(root->right).first&&abs(left-right)<=1) {
            return {true,1+max(left,right)};
        }
        return {false,1+max(left,right)};
    }
};
