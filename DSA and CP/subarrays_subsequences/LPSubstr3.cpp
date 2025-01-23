// using wiki approach of first finding the centre of the palindrome
// time = O(n^2)
// auxillary space = O(n)
pair <ll, ll> helper_ans(const string& s){
    ll low = -1;
    ll max_len = 0;
    ll n = s.size();
    for(int i = 0; i < n; i++){
        ll r = 0;
        while(i - r >= 0 && i + r <= n-1 && s[i-r] == s[i+r]) r++;
        r--;
        if(max_len < 2*r + 1){
            max_len = 2*r + 1;
            low = i - r;
        }
    }
    return {low, max_len};
    // note that max_len will always be odd
    // because of augumentaion
}

string longestPalindrome(string s) {
    string aug;
    for(auto ch: s){
        aug += "|";
        aug += ch;
    }
    aug += "|";
    pair <int, int> p = helper_ans(aug);
    ll low = p.fi;
    ll max_len = p.se;
    return s.substr(low/2, max_len/2);
}