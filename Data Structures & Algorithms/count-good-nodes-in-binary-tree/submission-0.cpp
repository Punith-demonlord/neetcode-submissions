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
    int goodNodes(TreeNode* root) {
        int count=0;
        int max=INT_MIN;
        goodNode(root,max,count);
        return count;

    }
    void goodNode(TreeNode* root,int max,int& count) {
        if (!root) {
            return ;
        }
        if (root->val>=max) {
            count++;
            max=root->val;
        }
        goodNode(root->left,max,count);
        goodNode(root->right,max,count);
    }
};
