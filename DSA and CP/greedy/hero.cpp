#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pl pair <ll, ll>
#define fi first
#define se second

struct monster{
    ll damage;
    ll restore;
};

int main(){
    ll n, H;
    cin >> n >> H;

    monster arr[n];
    for(ll i = 0; i < n; i++) cin >> arr[i].damage >> arr[i].restore;

    // comparator from erichto lecture 3
    auto cmp = [](const monster& m1, const monster& m2){
        ll p1 = m1.restore - m1.damage;
        ll p2 = m2.restore - m2.damage;

        // all the profitable monsters are put front in the row
        if(p1 >= 0 && p2 < 0) return true;
        if(p1 < 0 && p2 >= 0) return false;

        // for the monsters which are profitable, keep monsters in non-decreasing order of damages
        if(p1 >= 0 && p2 >= 0) return m1.damage < m2.damage;

        // for bad monsters keep monsters with high restore first
        return m1.restore > m2.restore;
    };

    sort(arr, arr + n, cmp);

    // goal: find the maximum number of monsters that could be killed
    vector <vector <ll>> dp(1+n, vector <ll> (1+n, INT_MAX));

    for(ll j = n-1; j >= 0; j--) dp[1][j] = min(dp[1][j+1], arr[j].damage);
    // dp[i][j] = Minimum hp required to get i monsters killed from [j:n)
    for(ll i = 2; i <= n; i++){
        for(ll j = n-i; j >= 0; j--){
            dp[i][j] = min(dp[i][j+1], max(arr[j].damage, - arr[j].restore + arr[j].damage + dp[i-1][j+1]));
        }
    }

    ll maximum_monsters = n;
    for(ll i = 1; i <= n; i++){
        if(dp[i][0] > H){
            maximum_monsters = i-1;
            break;
        }
    }
    
    // Maximum number of monsters that could be killed
    cout << maximum_monsters << "\n";
}
