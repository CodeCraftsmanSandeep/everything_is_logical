#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pl pair <ll, ll>
#define ppl pair <ll, pl>
#define fi first
#define se second

int main(){
    {
        // wanting to treat only first element as key
        auto comp = [](const ppl& p1, const ppl& p2){
            return p1.fi > p2.fi;
        };
        set <ppl, decltype(comp)> q(comp), next(comp);        
        q.insert({4, {1, 2}});
        q.insert({4, {2, 3}});
        q.insert({4, {1, 2}});
        q.insert({5, {1, 2}});

        cout << q.size()  << "\n"; // output 2
    }
    {
        // wanting complete pair <ll, pair <ll, ll>> to treat as key
        auto comp = [](const ppl& p1, const ppl& p2){
            if(p1.fi > p2.fi) return p1.fi > p2.fi;
            if(p1.fi < p2.fi) return false;
            if(p1.fi == p2.fi) return p1.se > p2.se;
        };
        set <ppl, decltype(comp)> q(comp), next(comp);        
        q.insert({4, {1, 2}});
        q.insert({4, {2, 3}});
        q.insert({4, {1, 2}});
        q.insert({5, {1, 2}});

        cout << q.size() << "\n"; // output 3
    }
    // I think you what I am trying to say by this code??? Dont you?? :-)
}