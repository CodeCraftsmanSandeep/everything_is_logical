// O(n ^ 2) time
// O(n ^ 2) space

class TrieNode{
private:
    TrieNode* child[26];
public:
    TrieNode(){
        for(int i = 0; i < 26; i++) child[i] = nullptr;
    }
    friend int countDistinctSubstring(string );
};

/*You are required to complete this method */
int countDistinctSubstring(string s){
    TrieNode* root = new TrieNode();
    
    int distinctSubStrings = 1; // 1 for empty substring
    for(int i = 0; i < s.size(); i++){
        TrieNode* trav = root;
        for(int j = i; j < s.size(); j++){
            if(trav->child[s[j] - 'a'] == nullptr){
                trav->child[s[j] - 'a'] = new TrieNode();
                distinctSubStrings++;
            }
            trav = trav->child[s[j] - 'a'];
        }
    }
    return distinctSubStrings;
}