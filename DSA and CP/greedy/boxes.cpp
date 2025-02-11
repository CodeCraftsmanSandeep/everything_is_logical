#include <bits/stdc++.h>
using namespace std;

#define ll long long int

struct item{
    ll weight;
    ll strength;

    item(){}
};

int main(){
    ll n;
    cin >> n;

    item ele[n];
    for(ll i = 0; i < n; i++){
        cin >> ele[i].weight >> ele[i].strength;
    }

    
}