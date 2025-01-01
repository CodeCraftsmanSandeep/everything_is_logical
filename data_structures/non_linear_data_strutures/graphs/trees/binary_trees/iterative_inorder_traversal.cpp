class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> preorder;
        stack <TreeNode*> st;
        while(!st.empty() || root != nullptr){
            while(root != nullptr){
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
                
            preorder.push_back(root->val);
            root = root->right;
        }
        return preorder;
    }
};