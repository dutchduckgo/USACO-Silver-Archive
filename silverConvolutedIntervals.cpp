#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>

bool sortbysec(const pair<ll, ll> &a, const pair<ll,ll> &b) {
    return (a.second < b.second);
}

int main() {
    freopen("convolutedIntervals.in", "r", stdin);
    freopen("convolutedIntervals.out", "w", stdout);
    ll N, M;
    cin >> N >> M;
    ll k = 2 * M + 1;
    vector <pair <ll, ll>> a;
    vector <pair <ll, ll>> b;
    a.resize(N);
    b.resize(N);
    for (ll i = 0; i < N; i ++) {
        cin >> a[i].first;
        cin >> a[i].second;

    }
    b = a;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), sortbysec);

    for (ll i = 0; i < k; i ++) {
        if(a[0].first * 2 > i || b[b.size() - 1].second * 2 < i) {
            cout << "0" << "\n";
            continue;
        }
        ll rslt = 0;
        ll l = 0, h = N;
        while (l + 1 < h) {
            ll mid = (l + h) / 2;
            if (a[mid].first * 2 <= k) l = mid + 1;
            else h = mid - 1;
        }
        queue<ll> bVals;
        for (ll j = 0; j < h; j ++) {
            bVals.push(a[j].second);
        }
        for (ll j = 0; j < h; j ++) {
            if (a[h].second * bVals.front() >= k) rslt ++;
            bVals.pop();
        }
        cout << rslt << "\n";
    }

}