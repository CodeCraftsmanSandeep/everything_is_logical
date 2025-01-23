class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2) {
        stack <Node*> ele1;
        stack <Node*> ele2;
        
        while(root1 != nullptr){
            ele1.push(root1);
            root1 = root1->left;
        }
        
        while(root2 != nullptr){
            ele2.push(root2);
            root2 = root2->left;
        }
        
        vector <int> ans;
        
        while(!ele1.empty() && !ele2.empty()){
            Node* curr;
            if(ele1.top()->data < ele2.top()->data){
                curr = ele1.top();
                ele1.pop();
                ans.push_back(curr->data);
                curr = curr->right;
                while(curr != nullptr){
                    ele1.push(curr);
                    curr = curr->left;
                }
            }else{
                curr = ele2.top();
                ele2.pop();
                ans.push_back(curr->data);
                curr = curr->right;
                while(curr != nullptr){
                    ele2.push(curr);
                    curr = curr->left;
                }
            }

        }
        while(!ele1.empty()){
            Node* curr = ele1.top();
            ele1.pop();
            ans.push_back(curr->data);
            curr = curr->right;
            while(curr != nullptr){
                ele1.push(curr);
                curr = curr->left;
            }
        }
        
        while(!ele2.empty()){
            Node* curr = ele2.top();
            ele2.pop();
            ans.push_back(curr->data);
            curr = curr->right;
            while(curr != nullptr){
                ele2.push(curr);
                curr = curr->left;
            }
        }
        return ans;
    }
};