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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
       vector<vector<int>> res;
       if (!root) {
            return res;
        }
       queue<TreeNode*> bfs;
       TreeNode* curr=root;
       bfs.push(curr);
       while (!bfs.empty()) {
            int qlen=bfs.size();
            vector<int> level;
            for (int i=0;i<qlen;i++) {
                TreeNode* node=bfs.front();
                bfs.pop();
                if (node) {
                    level.push_back(node->val);
                    if (node->left) {bfs.push(node->left);}
                    if (node->right) {bfs.push(node->right);}
                }
                
            }
            res.push_back(level);
        } 
        return res;
    }
};
