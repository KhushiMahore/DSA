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
    void inorder(TreeNode* root, vector<int>& array) {
        if (root == nullptr)
            return;
        inorder(root->left, array);
        array.push_back(root->val);
        inorder(root->right, array);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> array;
        inorder(root, array);
        int i = 0;
        int j = array.size() - 1;
        while (i < j) {
            int sum = array[i] + array[j];
            if (sum == k)
                return true;
            else if (sum < k)
                i++;
            else
                j--;
        }
        return false;
    }
};