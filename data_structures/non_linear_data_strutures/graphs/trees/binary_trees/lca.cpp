class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 ){
        if(root == nullptr) return nullptr;
        if(root->data == n1) return root;
        if(root->data == n2) return root;
        
        Node* left = lca(root->left, n1, n2);
        Node* right = lca(root->right, n1, n2);
        if(left != nullptr && right != nullptr) return root;
        if(left == nullptr) return right;
        return left;
    }
};