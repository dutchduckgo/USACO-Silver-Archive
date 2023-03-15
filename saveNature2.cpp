#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>

ll x, a, y, b, lc, k;
vi v;

int GCD (int a, int b) {
    return b == 0 ? a : GCD(b, a % b);
}

bool isValid(int t) {
    int s1 = t / lc, s2 = t / a, s3 = t / b - s1 + s2;
    return v[s1] * (x + y) + (v[s2] - v[s1]) * x + (v[s3] - v[s2]) * y >= k;
}


int main() {
    int q;
    cin >> q;
    while (q --) {
        int n;
        cin >> n;
        v.resize(n + 1, 0);
        for (int i = 1; i <= n; i ++) {
            cin >> v[i];
            v[i] /= 100;    
        }
        sort(v.begin() + 1, v.end(), greater<int>());
        for (int i = 1; i <= n; i ++) v[i] += v[i - 1];
        cin >> x >> a >> y >> b >> k;
        lc = a * b / GCD(a, b);
        if (x < y) {
            swap(x, y);
            swap(a, b);
        }
        if (!isValid(n)) {
            cout << -1 << "\n";
            continue;
        }
        int lo = 0, hi = n;
        while (lo + 1 < hi) {
            int mid = (lo + hi) / 2;
            if (isValid(mid)) hi = mid;
            else lo = mid;
        }
        cout << hi << "\n";
        
    }
}