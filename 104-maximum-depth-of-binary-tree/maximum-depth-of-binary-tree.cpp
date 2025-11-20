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
    void count(TreeNode* root, int depth, int& maxdepth) {
        maxdepth = max(maxdepth, depth);
        if(!root) return;
        if (root->left != nullptr)
            count(root->left, depth + 1, maxdepth);
        if (root->right != nullptr)
            count(root->right, depth + 1, maxdepth);
    }
    int maxDepth(TreeNode* root) {
        int maxdepth = 1;
        int mindepth = 1;
        if(!root) return 0;
        count(root, mindepth, maxdepth);
        return maxdepth;
    }
};