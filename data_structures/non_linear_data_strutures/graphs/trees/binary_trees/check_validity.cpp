class Solution{
    public:
    int find_index(const int& low, const int& high, int key, int inorder[]){
        for(int i = low; i <= high; i++) if(inorder[i] == key) return i;
        return -1;
    }
    bool get_postorder(int& index, int low, int high, int preorder[], int inorder[], vector <int>& postorder){
        if(low > high) return true;
        
        int key = preorder[index++];
        int i = find_index(low, high, key, inorder);
        if(i == -1) return false;
        
        if(!get_postorder(index, low, i-1, preorder, inorder, postorder)) return false;
        if(!get_postorder(index, i+1, high, preorder, inorder, postorder)) return false;
        postorder.push_back(key);
        return true;
    }
    
    bool checktree(int preorder[], int inorder[], int postorder[], int n) {
        vector <int> new_postorder;
        int index = 0;
        if(!get_postorder(index, 0, n-1, preorder, inorder, new_postorder)) return false;
        
        for(int i = 0; i < n; i++) if(new_postorder[i] != postorder[i]) return false;
        return true;
    }
};