class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector <int> preorder;
        stack <TreeNode*> st;

        while(!st.empty() || root != nullptr){
            if(root != nullptr){
                st.push(root);
                preorder.push_back(root->val);

                root = root->left;
            }else{
                root = st.top();
                st.pop();

                root = root->right;
            }
        }
        return preorder;
    }
};