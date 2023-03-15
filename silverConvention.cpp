#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, c;
    cin >> n >> m >> c;
    vector<int>times(n);
    while (n --) cin >> times[n];
    sort(times.begin(), times.end(), greater<int>());
    int low = 0;
    int high = times.size() - 1;
    int lastMiddle;
    while (low < high) {
        int middle = (high + low) / 2;
        if (middle = lastMiddle) break;
        bool simWorks = sim(times, middle, m, c);
        if (simWorks) 
            high = middle;
        else low = middle;
        lastMiddle = middle;
    }
    if (sim(times, high, m ,c)) {
        cout << high;
    }
    else cout << low;
}
bool sim(vector<int> times, int time, int m, int c) {
    int curlow = times[0];
    int count = 0;
    for (int i = 0; i < times.size(); i ++) {
        if (times[i] - curlow > time || count == c) {
            curlow == times[i];
            m --;
            count = 0;
        }
        count ++;
    }
    m --;
    if (m < 0) return false;
    return true;
}