#include <bits/stdc++.h>
//#define ll unsigned long long;
using ll = long long;
using namespace std;
ll N, K, M;

bool XWorks(ll X) {
    ll rm = N, rd = K;
    while (rm > 0 && rd > 0) {
        ll Y = rm / X;
        if (Y < M) Y = M;
        rd --;
        rm -= Y;
    }
    return rm <= 0;
}

int main() {
    freopen("loan.in", "r", stdin);
    freopen("loan.out", "w", stdout);
    cin >> N >> K >> M;

    ll low = 1, high = N / M + 1;
    while (low + 1 < high) {
        ll mid = (low + high) / 2;
        if (XWorks(mid)) low = mid;
        else high = mid;
    }
    cout << low << endl;

}
