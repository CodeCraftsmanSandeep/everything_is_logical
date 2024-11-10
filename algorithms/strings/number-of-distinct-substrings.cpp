
vector <int> findZFunction(const int n, const string s){
    vector <int> z(n, 0);
    int l = 0;
    int r = 0;
    for(int i = 1; i <= n-1; i++){
        if(i < r){
            // s[i-l : r - l) = s[i : r)
            z[i] = min(z[i - l], r-i);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if(i + z[i] > r){
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int repeatedPrefixes(string s){
    vector <int> z = findZFunction(s.size(), s);
    return *max_element(z.begin(), z.end());
}

int countDistinctSubstring(string s){
    int n = s.size();
    int count = 1; // empty substring
    for(int i = n-1; i >= 0; i--){
        // adding character s[i] to s[i+1:] from beginning
        count += (n-i - repeatedPrefixes(s.substr(i, n-i)));
    }
    return count;
}