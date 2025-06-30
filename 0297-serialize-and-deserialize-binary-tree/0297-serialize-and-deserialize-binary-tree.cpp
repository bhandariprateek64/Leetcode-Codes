class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "#";
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (node) {
                ans += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                ans += "#,";
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "#") return nullptr;

        stringstream ss(data);
        string word;
        getline(ss, word, ',');
        TreeNode* root = new TreeNode(stoi(word));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* parent = q.front(); q.pop();

            // Left child
            if (!getline(ss, word, ',')) break;
            if (word != "#") {
                TreeNode* left = new TreeNode(stoi(word));
                parent->left = left;
                q.push(left);
            }

            // Right child
            if (!getline(ss, word, ',')) break;
            if (word != "#") {
                TreeNode* right = new TreeNode(stoi(word));
                parent->right = right;
                q.push(right);
            }
        }
        return root;
    }
};
