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
        unordered_map<int,int> inorderMap;
        for (int i=0;i<inorder.size();i++) {
            inorderMap[inorder[i]]=i;
        }
        return buildTreek(preorder,inorderMap,preIn,0,inorder.size()-1);
    }
    TreeNode* buildTreek(vector<int>& preorder, unordered_map<int,int> & inorderMap,int &preIn,int left,int right) {
        if (left>right) {
            return nullptr;
        }
        int root=preorder[preIn++];
        int inIn=inorderMap[root];
        
        TreeNode* roote =new TreeNode(root);
        roote->left=buildTreek(preorder,inorderMap,preIn,left,inIn-1);
        roote->right=buildTreek(preorder,inorderMap,preIn,inIn+1,right);
        return roote;

    }
};
