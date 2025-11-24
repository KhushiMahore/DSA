/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return {};
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);
        while ((!s1.empty() || !s2.empty()))  {
            vector<int> level;
            while (!s1.empty()) {
                TreeNode* node = s1.top();
                s1.pop();
                level.push_back(node->val);
                if (node->left != nullptr)
                    s2.push(node->left);
                if (node->right != nullptr)
                    s2.push(node->right);
            }
            if (!level.empty())
                result.push_back(level);
            level.clear();
            while (!s2.empty()) {
                TreeNode* node = s2.top();
                s2.pop();
                level.push_back(node->val);
                if (node->right != nullptr)
                    s1.push(node->right);
                if (node->left != nullptr)
                    s1.push(node->left);
            }
            if (!level.empty())
                result.push_back(level);
            level.clear();
        }
        return result;
    }
};