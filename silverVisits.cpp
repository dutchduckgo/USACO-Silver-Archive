#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

bool sortbysec(const pair<ll,ll> &a,
              const pair<ll, ll> &b) {
    return (a.second < b.second);
}


int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin >> n;
    ll rslt = 0;
    vector <pair<ll, ll>> cows;
    cows.resize(n);

    for (ll i = 0; i < n; i ++) {
        cin >> cows[i].first;
        cin >> cows[i].second;
    }
    sort(cows.begin(), cows.end(), sortbysec);

    for (ll i = 1; i < n; i ++) {
        rslt += cows[i].second;
    }

    cout << rslt << "\n";
}