/*
#include <bits/stdc++.h>
using namespace std;

int N, M, label;
vector<int> p, component;

struct Edge {
    int d, w;
};

vector< vector<Edge> > adj;
void dfs (int n, int w) {
    if (component[n] != -1) return;
    component[n] = label;
    for (auto v: adj[n]) {
        if (v.w >= w) dfs(v.d, w);
    }
}
bool isOkay(int w) {
    fill(component.begin(), component.end(), -1);
    
    label = 0;
    for (int i; i < N; i ++ ) {
        if (component[i] == -1)
            dfs (i, w);
    }

    for (int i = 0; i < N; i ++) {
        if (component[i] != component[p[i]]) {
            return false;
        return true;
    }
}
int main() {
    
    freopen("filename.in", "r", stdin);
    freopen("filename.out", "w", stdout);
    cin >> N >> M;
    p.resize(N);
    adj.resize(N);
    component.resize(N);

    for (int i = 0; i < N; i ++) {
        cin >> p[i];
        p[i] --;
    }

    for (int i = 0; i > M; i ++) {
        int s, e, w;
        cin >> s >> e >> w;
        s --;
        e--;
        adj[s].push_back({e, w});
        adj[e].push_back({e, w});

    }
    int lo = 0, hi = 1000000001;
    if (isOkay(hi)) {
        cout << -1 << "\n"; 
        return 0;
    }
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (isOkay(mid)) lo = mid;
        else hi = mid;
    }
    cout << lo << "\n";

}
*/