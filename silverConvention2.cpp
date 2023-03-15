#include <bits/stdc++.h>
using namespace std;
vector<int> times;
int n, m, c;
int main() {

    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    cin >> n >> m >> c;
    times.resize(n, 0);
    while (n --) cin >> times[n];
    sort(times.begin(), times.end(), greater<int>());
    int low = 0;
    int high = times.size() - 1;

    while (low + 1 < high) {
        int mid = (low + high) / 2;
        if (isOK(mid)) high = mid;
        else low = mid;
    }
    cout << high << endl;

}
bool isOK(int wt) {
    int r = c, b = m, s = times[0];
    for (int i = 0; i < n; i ++) {
        if (times[i] - s > wt) {
            b --;
            s = times[i];
            r = c;
        }
        r --;
    }
    return b > 0;
}