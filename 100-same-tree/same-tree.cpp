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
    bool isSame = false;
    void check(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) {
            isSame = true;
            return;
        }
        if (p == NULL || q == NULL) {
            isSame = false;
            return;
        }
        if (p->val == q->val) {
            check(p->left, q->left);
            if (isSame == false)
                return;
            check(p->right, q->right);
            return;
        } else {
            isSame = false;
            return;
        }
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        check(p, q);
        return isSame;
    }
};