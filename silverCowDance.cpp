#include <bits/stdc++.h>
using namespace std;
int N, T;
vector<int> duration;

bool isOK(int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int pos = 0;
    for (; pos < k; pos ++ ) pq.push(duration[pos]); // add first k cows
    for (; pos < N; pos ++) {
        pq.push(pq.top() + duration[pos]); //add (smallest(top) + next cow) to pq
        pq.pop(); //pop smallest
    }
    while (pq.size() > 1 ) pq.pop(); //pop all but biggest
    return pq.top() <= T;

    
}
int main() {
    
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
    cin >> N >> T;
    duration.resize(N, 0);
    for (int i = 0; i < N; i ++) cin >> duration[i];
    
    int l = 1, h = N;
    while (l + 1 < h) {
        int mid = (l + h) / 2;
        if (isOK(mid)) h = mid;
        else l = mid;
    }
    
    cout << h << endl;
}