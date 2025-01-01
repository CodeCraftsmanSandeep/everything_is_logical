
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector <int> preorder;
        if(root == nullptr) return preorder;

        stack <TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode* curr_node = st.top();
            st.pop();
            preorder.push_back(curr_node->val);

            if(curr_node->right != nullptr) st.push(curr_node->right);
            if(curr_node->left != nullptr) st.push(curr_node->left);
        }
        return preorder;
    }
};