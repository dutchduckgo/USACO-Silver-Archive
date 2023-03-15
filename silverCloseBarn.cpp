#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
int N, M;
vector<vector<int>> adjList;
vector<bool> visited;
vector<bool> deleted;
int count = 0;

int dfs(int node) {
    if (visited[node] || deleted[node]) return 0;
    visited[node] = true;
    int rslt = 1;
    for(int next : adjList[node]) rslt += dfs(next);
    return rslt;
}

int main() {
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    cin >> N >> M; 
    adjList.resize(N);
    deleted.resize(N, false);
    visited.resize(N, false);
    for (int i = 0; i < M; i ++) { //setup adjList
        int a, b;
        cin >> a >> b;
        a --;
        b --;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    for (int i = 0; i < N; i ++) {
        fill(visited.begin(), visited.end(), false);
        int d;
        cin >> d;
        d --;
        if (dfs(d) == N - i) cout << "YES\n";
        else cout << "NO\n";
        deleted[d] = true;

    }
    


}

