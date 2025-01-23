
vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector <int> inorder, preorder, postorder;

    enum traversalType {PRE, IN, POST};
    stack < pair <TreeNode*, traversalType> > st;
    st.push({root, PRE});

    while(!st.empty()){
        if(st.top().second == PRE){
            preorder.push_back(st.top().first->data);
            st.top().second = IN;
            if(st.top().first->left != nullptr) st.push({st.top().first->left, PRE});
        }else if(st.top().second == IN){
            inorder.push_back(st.top().first->data);
            st.top().second = POST;
            if(st.top().first->right != nullptr) st.push({st.top().first->right, PRE});
        }else{
            postorder.push_back(st.top().first->data);
            st.pop();
        }
    }

    return {inorder, preorder, postorder};
}