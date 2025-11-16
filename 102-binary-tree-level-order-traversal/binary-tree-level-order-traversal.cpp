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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;
        ans.push_back({ root->val });
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();

                if (temp->left != nullptr) {
                    q.push(temp->left);
                    level.push_back(temp->left->val);
                }
                if (temp->right != nullptr) {
                    q.push(temp->right);
                    level.push_back(temp->right->val);
                }
            }
            if(level.size()!=0)
            ans.push_back(level);
        }
        return ans;
    }
};