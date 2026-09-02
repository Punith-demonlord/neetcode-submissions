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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return equivalent(p,q);
    }
    bool equivalent(TreeNode*p,TreeNode* q) {
        if (!p||!q) {
            if (!p&&!q) {
            return true;
            } else {return false;}
        }
        if (p->val==q->val&&equivalent(p->left,q->left)&&equivalent(p->right,q->right)) {
            return true;
        }
        return false;
    } 
};
