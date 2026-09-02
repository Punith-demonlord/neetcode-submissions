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
    int diameterOfBinaryTree(TreeNode* root) {
        int count=0;
        calculateDepth(root,count);
        return count;
    }
private:
    int calculateDepth(TreeNode* root,int &maxDiameter) {
        if (!root) {
            return 0;
        }
        int rightDepth=calculateDepth(root->right,maxDiameter);
        int leftDepth=calculateDepth(root->left,maxDiameter);
        maxDiameter=max(maxDiameter,rightDepth+leftDepth);
        return 1+max(rightDepth,leftDepth);
    }
};
