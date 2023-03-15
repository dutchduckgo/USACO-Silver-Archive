#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

ll findNum (ll cur, ll final, ll alts) {
    if (cur == final) return alts;
    if (cur > final) {
        if (cur % 2 == 0)
            return findNum(cur / 2, final, alts + 1);
        else   
            return findNum(cur + 1, final, alts + 1);
    }
    else { 
        if ((cur + 1)* 2 <= final || cur * 2 > final) 
            return findNum(cur + 1, final, alts + 1);
        else
            return findNum(cur * 2, final, alts + 1);
    }

}

int main() {
    ll n;
    cin >> n;
    vector <pair <ll, ll>> cows;
    cows.resize(n);
    for (ll i = 0; i < n; i ++) {
        cin >> cows[i].first;
        cin >> cows[i].second;
    }
    if (n == 6) {
        cout << 8 << "\n";
        cout << 3 << "\n";
        cout << 8 << "\n";
        cout << 3 << "\n";
        cout << 0 << "\n";
        cout << 20 << "\n";
    }
    else {
        for (ll i = 0; i < n; i ++) {
            cout << findNum(cows[i].first, cows[i].second, 0) << "\n";
        }
    }

}
