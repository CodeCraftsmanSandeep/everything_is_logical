vector <int> getZFunction(const string& str){
    int n = str.size();
    vector <int> z(n, 0);
    int l = 0;
    int r = 0;
    
    for(int i = 1; i < n; i++){
        if(r > i) z[i] = min(r-i, z[i-l]);
        while(i + z[i] < n && str[z[i]] == str[i + z[i]]) z[i]++;
        if(i + z[i] > r){
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int repeatedSuffixes(string str){
    reverse(str.begin(), str.end());
    vector <int> z = getZFunction(str);
    return *max_element(z.begin(), z.end());
}


/*You are required to complete this method */
int countDistinctSubstring(string s){
    // O(n ^ 2) : Time
    // O(n) : Auxillary space
    
    string pref;
    int distinctSubStrings = 0;
    for(auto ch: s){
        pref += ch;
        distinctSubStrings += pref.size() - repeatedSuffixes(pref);
    }
    return distinctSubStrings + 1; // +1 for emptry substring
}