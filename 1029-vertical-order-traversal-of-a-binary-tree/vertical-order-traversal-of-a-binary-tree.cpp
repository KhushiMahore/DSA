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
map<int, map<int, vector<int>>> mpp;
    void verticalOrder(TreeNode* root, int col, int row) {
        if (root == nullptr)
            return;
        mpp[col][row].push_back(root->val);
        if (root->left != nullptr)
            verticalOrder(root->left, col - 1, row + 1);

        if (root->right != nullptr)
            verticalOrder(root->right, col + 1, row + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        verticalOrder(root, 0, 0);
        vector<vector<int>> ans;

        for (auto& firstM : mpp) { 
            vector<int> level;
            for (auto& secondM : firstM.second) {
                auto& vec = secondM.second;
                sort(vec.begin(), vec.end());
                for (int v : vec)
                    level.push_back(v);
            }
            ans.push_back(level);
        }
        return ans;
    }
        
    
};