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
    vector<int> rightSideView(TreeNode* root) {
       if (!root) {
        return {};
       }
        vector<int> res;
        TreeNode* curr=root;
        vector<vector<int>> pro;
        queue<TreeNode*> q;
        q.push(root);
        int curre=0;
        while (!q.empty()) {
            int size=q.size();
            pro.push_back({});
            for (int i=0;i<size;i++) {
                TreeNode* node=q.front();
                q.pop();
                pro[curre].push_back(node->val);
                if (node->left) {q.push(node->left);}
                if (node->right) {q.push(node->right);}
            }
            curre++;
        }
        for (vector<int> num:pro) {
            res.push_back(num.back());
        }
        return res;
    }
};
