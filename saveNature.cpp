#include <bits/stdc++.h>
//#define ll long long;
using ll = long long;

using namespace std;
ll q, n, x, a, y, b, k;

bool midWorks(ll rslt, vector<ll> tickets) {
    
}
int GCD (int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    cin >> q;
    while (q --) {
        vector<ll> tickets;
        cin >> n;
        for (ll i = 0; i < n; i ++) cin >> tickets[i];
        sort(tickets.begin(), tickets.end(), greater<int>());
        cin >> x >> a >> y >> b >> k;
        
        ll lo = 1, hi = n;
        while (lo + 1 < hi) {
            ll mid = (lo + hi) / 2;
            if (midWorks(mid, tickets)) hi = mid;
            else lo = mid;

        }
        if (hi == n) cout << -1 << endl; // hi stays hi
        cout << lo << endl;
    }
}
