/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
  
        string serialize(TreeNode * root) {
            string tree = "";
            if (root == NULL)
                return tree;

            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty()) {
                TreeNode* node = q.front();
                q.pop();

                if (node) {
                    tree += to_string(node->val) + ",";
                    q.push(node->left);
                    q.push(node->right);
                } else
                    tree += "n,";
            }
            return tree;
        }
    

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       
            if (data == "")
                return NULL;

            vector<string> nodes;
            string temp = "";

            for (char c : data) {
                if (c == ',') {
                    nodes.push_back(temp);
                    temp = "";
                } else
                    temp += c;
            }

            TreeNode* root = new TreeNode(stoi(nodes[0]));
            queue<TreeNode*> q;
            q.push(root);

            int i = 1;
            while (!q.empty() && i < nodes.size()) {
                TreeNode* node = q.front();
                q.pop();
                if (nodes[i] != "n") {
                    node->left = new TreeNode(stoi(nodes[i]));
                    q.push(node->left);
                }
                i++;

                if (i < nodes.size() && nodes[i] != "n") {
                    node->right = new TreeNode(stoi(nodes[i]));
                    q.push(node->right);
                }
                i++;
            }
            return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));