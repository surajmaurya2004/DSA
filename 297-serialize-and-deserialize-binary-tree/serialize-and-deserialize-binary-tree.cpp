class Codec {
public:

    // Serialize
    void serializeHelper(TreeNode* root, string &s) {
        if(root == NULL) {
            s += "null,";
            return;
        }

        s += to_string(root->val) + ",";
        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }

    string serialize(TreeNode* root) {
        string s = "";
        serializeHelper(root, s);
        return s;
    }

    // Deserialize
    TreeNode* deserializeHelper(vector<string> &data, int &index) {
        if(data[index] == "null") {
            index++;
            return NULL;
        }

        TreeNode* node = new TreeNode(stoi(data[index++]));
        node->left = deserializeHelper(data, index);
        node->right = deserializeHelper(data, index);

        return node;
    }

    TreeNode* deserialize(string data) {
        vector<string> nodes;
        string temp = "";

        for(char c : data) {
            if(c == ',') {
                nodes.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }

        int index = 0;
        return deserializeHelper(nodes, index);
    }
};