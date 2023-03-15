#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> t, w;


vector< vector<int> > adj;
void dfs(int n, int p) {
    for (auto v : adj[n]) {
        if (v != p) dfs(v, n);
    }
    if (p >= 0) w[p] = (w[p] + 12 - w[n]) % 12;
}

int main() {
    freopen("clocktree.in", "r", stdin);
    freopen("clocktree.out", "w", stdout);
    cin >> n;
    t.resize(n);
    adj.resize(n);

    for (int i = 0; i < n; i ++) cin >> t[i];
    
    for (int i = 0; i < n - 1; i ++) {
        int s, e;
        cin >> s >> e; 
        s --; e --;
        adj[s].push_back(e);
        adj[e].push_back(s);

    }

    int rslt = 0;
    for (int i = 0; i < n; i ++) {
        w = t;
        dfs(i, -1);
        if (w[i] == 1 || w[i] == 0) rslt ++;
    }
    cout << rslt << "\n";

}