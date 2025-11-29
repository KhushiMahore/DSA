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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return order(preorder, inorder);
    }
    TreeNode* order(vector<int> pre, vector<int> in) {
        if (pre.size() == 0)
            return nullptr;
        int rootValue = pre[0];
        TreeNode* root = new TreeNode(rootValue);
        int index = 0;
        while (in[index] != rootValue)
            index++;
        vector<int> leftIn(in.begin(), in.begin() + index);
        vector<int> rightIn(in.begin() + index + 1, in.end());
        int leftSize= leftIn.size();
        vector<int> leftPre(pre.begin() + 1, pre.begin() + 1 +leftSize );
        vector<int> rightPre(pre.begin() +1+leftSize, pre.end());
        root->left = order(leftPre, leftIn);
        root->right = order(rightPre, rightIn);
        return root;
    }
}

;