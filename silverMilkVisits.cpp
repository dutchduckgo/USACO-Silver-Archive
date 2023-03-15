#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>

int N, M, label = 0;
vector<vector<int>> adj;
vector<int> comp;
string s;

void dfs (int n, int l) {
    if (comp[n] != -1) return;
    comp[N] = l;
    for (int next : adj[N]) {
        if (s[n] == s[next])
            dfs(next, 1);
    }
}

int main() {
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);

    cin >> N >> M;
    adj.resize(N);
    comp.resize(N, -1);
    getline(cin, s);
    getline(cin, s);
    for (int i = 0; i < N - 1; i ++) {
        int s, e;
        cin >> s >> e;
        s --;
        e --;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    for (int i = 0; i < N; i ++) { //label comps
        if (comp[i] == -1) dfs(i, label ++);
    }

    for (int i = 0; i < M; i ++) {
        int a, b;
        char p;
        cin >> a >> b;
        a--;
        b--;
        cin >> p;
        cout << ((comp[a] != comp[b] || s[a] == p) ? "1" : "0"); //if start label =/= end label, happy
    }
    cout << "\n";


}