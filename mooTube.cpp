#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e5;

vector<pair<int, int>> adj[MAXN+1]; // adjacency list for the graph
bool visited[MAXN+1]; // to mark visited nodes during the DFS
int relevance[MAXN+1]; // to store the minimum relevance along the path to each node

void dfs(int node, int k) {
    visited[node] = true;
    for (auto& neighbor : adj[node]) {
        int next_node = neighbor.first;
        int next_relevance = neighbor.second;
        if (!visited[next_node]) {
            relevance[next_node] = min(relevance[node], next_relevance);
            if (relevance[next_node] >= k) 
                dfs(next_node, k);
        }       
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n-1; i++) {
        int p, q, r;
        cin >> p >> q >> r;
        adj[p].push_back({q, r});
        adj[q].push_back({p, r});
    }
    for (int i = 0; i < q; i++) {
        int k, v;
        cin >> k >> v;
        fill_n(visited, n+1, false);
        fill_n(relevance, n+1, 1e9); // initialize relevance to a large value
        int count = 0;
        dfs(v, k);
        for (int j = 1; j <= n; j++) {
            if (relevance[j] >= k) 
                count++;
        }
        cout << count-1 << endl; // exclude the starting video from the count
    }
    return 0;
}