#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    long long ways = 1;
    for (int i = 0; i < k; i++) {
        ways = (ways * m) % MOD;
    }

    for (int i = k; i < n; i++) {
        ways = (ways * (m - 1)) % MOD;
    }

    cout << ways << endl;

    return 0;
}
