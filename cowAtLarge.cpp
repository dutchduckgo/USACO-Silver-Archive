#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

vector<int> adj[MAXN];
int dist[MAXN], exit_barns[MAXN];

void dfs(int u, int p, int d) {
    dist[u] = d;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(k, -1, 0);

    int num_exit_barns = 0;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == 1) {
            exit_barns[++num_exit_barns] = i;
        }
    }

    int ans = 0;
    for (int i = 1; i <= num_exit_barns; i++) {
        int u = exit_barns[i];
        int max_dist = -1;
        for (int v : adj[u]) {
            if (v != k) {
                max_dist = max(max_dist, dist[v]);
            }
        }
        ans = max(ans, max_dist + 1);
    }

    cout << ans << endl;

    return 0;
}
