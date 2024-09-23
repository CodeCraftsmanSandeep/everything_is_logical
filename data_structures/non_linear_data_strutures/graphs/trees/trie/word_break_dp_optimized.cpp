#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // Time: O(n^2 * hashing_time)
    // Space: O(n)
    int wordBreak(int k, string s, vector<string> &dictionary) {
        unordered_set <string> dict;
        for(auto &ele: dictionary) dict.insert(ele);
        int n = s.size();
        
        // for i in matched_index
        // s[i:] is in workBreak string
        vector <int> matched_index;
        matched_index.push_back(n);
        for(int i = n-1; i >= 0; i--){
            string sub_string;
            int prev = i;
            for(int k = matched_index.size() - 1; k >= 0; k--){
                int j = matched_index[k];
                while(prev < j) sub_string += s[prev++];
                if(dict.find(sub_string) != dict.end()){
                    matched_index.push_back(i);
                    break;
                }
            }
        }
        return matched_index.back() == 0;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}