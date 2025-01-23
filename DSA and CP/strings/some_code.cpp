//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int countDistinctSubstring(string s);

int main()
{
 int t,l,i,j;
 int temp;
    cin>>t;
 while(t--){
 string s;
  cin>>s;
  cout<<countDistinctSubstring(s)<<endl;

 
cout << "~" << "\n";
}
}

/*You are required to complete this method */
int countDistinctSubstring(string s){
    map <string, int> freq;
    int n = s.size();
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            freq[s.substr(i, j - i + 1)]++;
        }
    }
    return freq.size();
}
