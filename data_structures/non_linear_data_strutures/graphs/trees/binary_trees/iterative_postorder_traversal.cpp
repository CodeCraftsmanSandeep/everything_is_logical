class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* prev = nullptr;
        stack <TreeNode*> st;
        vector <int> postorder;

        while(!st.empty() || root != nullptr){
            while(root != nullptr){
                st.push(root);
                root = root->left;
            }
            root = st.top();

            if(root->right == nullptr || root->right == prev){
                postorder.push_back(root->val);
                prev = root;
                root = nullptr;
                st.pop();
            }else root = root->right;
        }
        return postorder;
    }
};