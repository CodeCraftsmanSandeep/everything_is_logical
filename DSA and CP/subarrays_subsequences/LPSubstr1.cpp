// another apporach
// O(n^2) time
// O(1) space
string longestPalin (string str){
    int n = str.size();
    int start = 0;
    int max_len = 1;
    for(int i = 0; i < n; i++){
        int low = i-1;
        int high = i + 1;
        while(low >= 0 && str[i] == str[low]) low--;
        while(high < n && str[i] == str[high]) high++;
        while(low >= 0 && high < n && str[low] == str[high]){
            low--;
            high++;
        }
        int len = (high-1) - (low + 1) + 1;
        if((len > max_len) || (len == max_len && low+1 < start)){
            start = low + 1;
            max_len = len;
        }
    }
    return str.substr(start, max_len);
}