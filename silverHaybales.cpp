#include <bits/stdc++.h>
using namespace std;

vector<int> hayBales;
int main() {
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    int N, Q;
    cin >> N >> Q;
    hayBales.resize(N , 0);
    for (int i = 0; i < N; i ++) cin >> hayBales[i];
    sort(hayBales.begin(), hayBales.end());


    for (int i = 0; i < Q; i ++) {
        int s, e;
        cin >> s >> e;
        auto sp = lower_bound(hayBales.begin(), hayBales.end(), s);
        auto ep = upper_bound(hayBales.begin(), hayBales.end(), e);
        cout << ep - sp << endl;
    }


}