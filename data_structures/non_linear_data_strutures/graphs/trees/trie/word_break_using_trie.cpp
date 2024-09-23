class Trie;

class TrieNode{
private:
    char data;
    TrieNode** child = new TrieNode*[26];
    bool isWord = false;
    
public:
    TrieNode(){
        for(int i = 0; i <= 25; i++) child[i] = nullptr;
    }
    TrieNode(char ch): data(ch) {
        for(int i = 0; i <= 25; i++) child[i] = nullptr;
    }

    friend class Trie;
};

class Trie{
    TrieNode* root = new TrieNode('#');
    
    void insertHelper(const string& str, int i, TrieNode* node){
        if(i == str.size()) return;
        if(node->child[str[i] - 'a'] == nullptr) node->child[str[i] - 'a'] = new TrieNode(str[i]);
        if(i + 1 == str.size()) node->child[str[i] - 'a']->isWord = true;
        insertHelper(str, i + 1, node->child[str[i] - 'a']);
    }
    
    bool isWordBreakHelper(const string& str, int i, TrieNode* node, vector <bool>& isBreakable){
        if(i == str.size()) return node->isWord;
        if(node->child[str[i] - 'a'] == nullptr) return false;
        if(node->child[str[i] - 'a']->isWord && isBreakable[i+1]) return true;
        return isWordBreakHelper(str, i+1, node->child[str[i] - 'a'], isBreakable);
    }
public:
    void insert(const string& str){
        insertHelper(str, 0, root);
    }
    
    bool isWordBreak(const string& str){
        vector <bool> isBreakable(str.size() + 1, false);
        isBreakable[str.size()] = true;
        for(int i = str.size() - 1; i >= 0; i--) isBreakable[i] = isWordBreakHelper(str, i, root, isBreakable);
        return isBreakable[0];
    }
};

class Solution{
public:
    int wordBreak(string s, vector<string> &dictionary) {
        Trie obj;
        for(auto& ele: dictionary) obj.insert(ele);
        return obj.isWordBreak(s);
    }
};