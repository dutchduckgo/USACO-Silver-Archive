#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> p;
pair<int, pair<int, int>> wh[1001];

bool validate (int w) {
    vector<int> labels;
    labels.resize(N, -1);
    int labelN = -1;
    for (int i = 0; i < M; i ++) {
        if (labels[i] < 0)
            //dfs(0, labelN, labels);
        labelN ++;
    }
}
/*
void dfs(int node, int labelN, vector<int> labels) {
    labels[node] = labelN;
    for (int next : adjList[node]) {
        if (labels[next] < 0) dfs(next, labelN + 1, labels);
    }
}
*/

int main() {
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    cin >> N >> M;
    p.resize(N, 0);
    int maxW = 0;

    for (int i = 0; i < N; i ++) {
        cin >> p[i];
        p[i] --;
    }
    for (int i = 0; i < M; i ++) {
        cin >> wh[i].second.first >> wh[i].second.second >> wh[i].first;
        wh[i].second.first --;
        wh[i].second.second --;
        maxW = max(maxW, wh[i].first);
    }
    sort(wh, wh + M);
    int lo = 0, hi = maxW;
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