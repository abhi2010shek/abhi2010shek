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
        int res = 0;
        process(root, res);
        return res;
    }
private:
    int process(TreeNode* node, int& res) {
        if (node == nullptr) {
            return -1;
        }
        int left = process(node->left, res) + 1;
        int right = process(node->right, res) + 1;
        res = std::max(res, left + right);
        return std::max(left, right);
    }
};