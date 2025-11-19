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
    vector<int> postorderTraversal(TreeNode* root) {
         vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* node = root;
        TreeNode *prevtop=nullptr;
        if (root == nullptr)
            return ans;

        while (node!=nullptr || !st.empty()) {
            
            while (node != nullptr ) {
                st.push(node);
                node=node->left;
            } 
                node = st.top();
                if(node->right!=nullptr && prevtop!=node->right){
                    node=node->right;
                   
                }
                else{
                    ans.push_back(node->val);
                    prevtop=node;
                    st.pop();
                    node=nullptr;
                }
        }
        return ans;
    }
};