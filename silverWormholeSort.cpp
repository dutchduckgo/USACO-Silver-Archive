#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
int N, M;
vector<int> p;
pair<int, pair<int, int>> wh[1001];
int group[1001];

bool validate (int w) {
    int index = lower_bound(wh, wh + M, (w, (0, 0))) - wh;
    vector<int> adjList[1000000];
    for (int i = index; i < M; i ++) {
        int x = wh[i].second.first;
        int y = wh[i].second.second;

        adjList[x].push_back(y);
        adjList[y].push_back(x);

    }
    int visited[1000000];
    for (int i = 0; i < N; i ++) {
        visited[i] = -1;
    }
    int count = 0;
    queue<int> q;
    
    for (int i = 0; i < N; i ++) {
        if (visited[i] < 0) {
            q.push(i);
        }
        visited[i] = count;
        while (!q.empty()) {
            int x = q.front();
            for (int j : adjList[x]) {
                q.push(j);
                visited[j] = count;
            }
        }
        count ++;
    }
    for (int i = 0; i < N; i ++) {
        if (visited[i] != visited[p[i]])
        return false;
    }
    return true;
}


int main() {
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    cin >> N >> M;
    p.resize(N, 0);
    int maxW = 0;

    for (int i = 0; i < N; i ++) {
        cin >> p[i];
        p[i] --;
        group[i] = i;
    }
    for (int i = 0; i < M; i ++) {
        cin >> wh[i].second.first >> wh[i].second.second >> wh[i].first;
        wh[i].second.first --;
        wh[i].second.second --;
        maxW = max(maxW, wh[i].first);
    }
    sort(wh, wh + M);
    int lo = 0, hi = 2000000000;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (validate(mid)) {
            lo = mid;
        }
        else hi = mid;
    }
    if (lo > maxW)  {
        cout << -1 << endl;
    }
    return 0;
    cout << lo << endl;
}